#QtDemo #CS/Qt 
## 整体流程
1. connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->battery, SLOT(setValue(int)));
2. ==Battery::setValue(double value);== 
	1. 设置isForward，决定动画移动方向
	2. 更新this->value = value
	3. Q_EMIT valueChanged(value); 发出valueChanged(value)信号，这应该是给其他操作用的，这是一个控件的责任？
	4. 判断是否启用动画，
		1. 如果启用，那么就启动==定时器timer==`。初始化时执行了 `connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));`
		2. 如果未启用，那么不启动定时器，直接将currentValue = value，这样就没有动画效果了。
	5. 定时器timeout()后，==调用updateValue==()，改变currentValue ` currentValue +/- = updateValue`。如果currentValue >= value了，即已经绘制完了动画，那么就timer->stop()停止定时器
	6. 调用update()，安排一次绘制事件，以调用paintEvent()
	7. 进入==paintEvent==() 执行`Battery::drawBg(QPainter *painter)`，根据currentValue更新界面，实现动画效果
重要参数：
- value 实际值
- currentValue 用于动画的当前值，会逐步增加
- timer 定时器，用于修改currentValue并调用update()
## Anki
### 页面改变后安排重绘
使用this->update()安排一次重绘事件
### update()后会发生什么
[Qt自绘常用刷新绘制函数update()用法记录原创](https://blog.csdn.net/weixin_42661333/article/details/127066570)

### Qt中的Q_EMIT宏的作用，不是已经存在emit了吗
一些第三方库如boost会使用emit等关键字，所以这里避免冲突
实际也是emit的作用，发射信号

### 绘制圆角矩形 函数原型；圆角范围
函数原型：void QPainter::drawRoundRect(const QRectF & r, int xRnd = 25, int yRnd = 25)
0是有角的角，99是最大圆度。填充的矩形的大小为r.size()。描边矩形的大小为r.size()加上笔的宽度。
### 绘制圆角矩形的原理；为什么0表示直角，99表示最大圆度？
void QPainter::drawRoundRect(const QRectF & r, int xRnd = 25, int yRnd = 25)
1. 将Rect分为4个Rect区间，分别为左上角RectA、右上角RectB、左下角RectC、右下角RectD
2. xRnd 表示每个小Rect区间占Rect宽度百分比、yRnd表示高度的百分比
```c++ fold
//图形1
QPainter paint(this);
paint.setRenderHint(QPainter::Antialiasing);
 
// 首先绘制一个底色为白色的大小为220，300的主题矩形框
paint.setBrush(QColor(255,255,255));
paint.drawRect(0,0,220,300);
paint.setBrush(Qt::transparent);
 
// 绘制黑色的大小为160，220的矩形框，也是目的框，为了和下面圆角矩形框做对比
paint.setPen(Qt::black);
paint.drawRect(20,20,160,220);
// 设置画笔颜色为红色
paint.setPen(Qt::red);
 
// 绘制A、B、C、D
paint.drawEllipse(20,20,128,88);
paint.drawEllipse(52,20,128,88);
paint.drawEllipse(20,152,128,88);
paint.drawEllipse(52,152,128,88);
 
// 绘制一个和目的框大小相同的圆角矩形，颜色为蓝色
paint.setPen(Qt::blue);
paint.drawRoundRect(20,20,160,220,80,40);

---------------------------------------------------
//图形2
QPainter paint(this);
paint.setRenderHint(QPainter::Antialiasing);
paint.setBrush(QColor(255,255,255));
paint.drawRect(0,0,220,300);
paint.setBrush(Qt::transparent);
 
paint.setPen(Qt::black);
paint.drawRect(20,20,160,220);
// 绘制A、B、C、D
paint.setPen(Qt::green);
paint.drawRect(20,20,128,88);
paint.setPen(Qt::blue);
paint.drawRect(52,20,128,88);
paint.setPen(Qt::green);
paint.drawRect(20,152,128,88);
paint.setPen(Qt::blue);
paint.drawRect(52,152,128,88);
 
paint.setPen(Qt::blue);
paint.drawRoundRect(20,20,160,220,80,40);
-------------------------------------------------
//合并俩图形
QPainter paint(this);
paint.setRenderHint(QPainter::Antialiasing);
paint.setBrush(QColor(255,255,255));
paint.drawRect(0,0,220,300);
paint.setBrush(Qt::transparent);
 
paint.setPen(Qt::black);
paint.drawRect(20,20,160,220);
 
paint.setPen(Qt::red);
paint.drawEllipse(20,20,128,88);
paint.drawEllipse(52,20,128,88);
 
paint.drawEllipse(20,152,128,88);
paint.drawEllipse(52,152,128,88);
 
paint.setPen(Qt::green);
paint.drawRect(20,20,128,88);
 
paint.setPen(Qt::blue);
paint.drawRect(52,20,128,88);
 
paint.setPen(Qt::green);
paint.drawRect(20,152,128,88);
 
paint.setPen(Qt::blue);
paint.drawRect(52,152,128,88);
 
paint.setPen(Qt::blue);
paint.drawRoundRect(20,20,160,220,80,40);
```
![[Pasted image 20240216214317.png]]![[Pasted image 20240216214422.png]]![[Pasted image 20240216214546.png]]
那么0,0表示没有小Rect，那么就没有椭圆边，都是矩形边。
而99,99表示小Rect沾满整个Rect，那么都是椭圆边

### QLinearGradient的作用；其他类似的呢；共同父类
1.
这里QLinearGradient是线性渐变类，常与QPainter联合作为brush刷图层实现渐变颜色效果。
类似的还有QConicalGradient弧度渐变类、QRaidialGradient半径渐变类
2.是QGradient类
### QLinearGradient使用的注意点；垂直和水平方向如何设置
```cpp
setStart(x, y);  
setFinalStop(x，y+5);
//这里的两个方法需要一起使用，
//垂直线性渐变: setStart(0,10) 与setFinalStop(0,30) ，从高度为10刷到高度为30。
//水平线性渐变: 只有y相同
```
### QLinearGradient的setColorAt()作用
```cpp
void setColorAt ( qreal position, const QColor & color ); //设置梯度颜色, position处于0~1之间
Linear.setColorAt(0,Qt::red);
Linear.setColorAt(1,Qt::blue);
//那么这就是从起始点为红色，结束点为蓝色渐变
```
### QLinearGradient QRadialGradient QConicalGradient初始化（构造函数）
1.QLinearGradient(qreal x1,qreal y1,qreal x2,qreal y2) 分别表示起始点，结束点
2.QRadialGradient Radial(0,0,120,0,0);    //设置圆的原点和焦点在中心,半径120
前两个参数表示圆心，中间的是radius圆半径，后两个是焦点位置（颜色的起始位置）
![[Pasted image 20240217090936.png]]
3.QConicalGradient Conical(0,0,30);    //设置点在中心,角度为30
![[Pasted image 20240217090806.png]]
QConicalGradient(qreal x1,qreal y1,qreal angle) 分别表示尖的位置和起始颜色位置的角度（逆时针渐变）
### QLinearGradient 如何与QPainter联合使用
```cpp
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    QLinearGradient Linear(100,100,100,200);        //垂直渐变

    Linear.setColorAt(0,Qt::red);
    Linear.setColorAt(1,Qt::blue);

    painter.setBrush(Linear);
    painter.setPen(Qt::transparent);
    painter.drawRect(100,100,100,100);          //100,100 到200,200
}
```
![[Pasted image 20240217085952.png]]
### painter.setPen(Qt::transparent); 与 painter.setPen(Qt::NoPen);的区别
- `painter.setPen(Qt::transparent);` 会将画笔设置为透明，这意味着画出的线条将是透明的，但仍将占据空间。
- `painter.setPen(Qt::NoPen);` 会将画笔设置为无画笔，这意味着不会画出任何线条。

