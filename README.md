# LED256

* 大一下学期，学院，科协举办第一届流水灯大赛（搞了两年觉得太简单，就不搞流水灯改搞车了（初级赛））

## 全彩点阵(第二名)
* 当时比赛时学长指出，这是真彩，不是全彩

* 大一和几个同学参加学院流水灯大赛的作品代码，拼命榨干了51单片机的资源，虽已经历很多全国赛事，至今很为这段代码骄傲。
* 方案
    - 颜色控制
        + 使用三色雾状灯冒LED，共阴引脚。
        + 当时pwm控制颜色的技术不是很成熟，也尝试过了，最终采用I2C控制下的DAC（***TLC5620）***控制颜色的方案：将64个灯的红色阳极接在一起，接到DAC的*chn0*；将64个灯的绿色阳极接在一起，接到DAC的*chn1*；将64个灯的蓝色阳极接在一起，接到DAC的*chn2*
        + 通过控制DAC的输出电压，分别控制每个灯的颜色。
    - 图案控制
        + 扫描技术
        + 使用多个译码器（74hc138，74HC154）组合后逐个扫描64个灯的阴极。
        + 当时申请芯片搞到TI拉黑我校。。。
    - 控制
        + 51单片机，原型验证用的是STC89C52，后面ROM，速度告急，在宏晶官网找了一款引脚完全兼容，，节拍更快的型号换上去，把晶振速度换大。
        + 多个定时器和延时调度
            * 无源蜂鸣器播放音乐
            * 刷新颜色，消隐
            * 保持图片，换图
    - 刷图大致流程
        >
        > for (imageCnt = 0 ;imageCnt < ? ;imageCnt ++):
        >       for (imageDelayCnt = 0;imageDelayCnt < ? ; imageDelayCnt ++ ):
        >           for ( lightCnt = 0 ; lightCnt < 64; lightCnt ++ ):   
        >               decoder select (lightCnt)
        >               DAC set color (red,green,blue)
        >               __nop__(3);
        >               DAC set color (0,0,0)
        >           

### Contributors
* Xiangjie Wu
* Songhuan Huang
* Wentao Sun
* Ruige Lee

---------------------------------------------------------------

## 风火轮（第一名）
* 做完摇摇棒，就想到了把摇摇棒安装在自行车的车轮上，网上搜，还真有
* 采用霍尔传感器，需要在车轮上贴一个磁铁标记起始位置
* 每次检测到磁铁后，开始刷图案

* [申请了实用新型专利](http://www.wanfangdata.com.cn/details/detail.do?_type=patent&id=CN201620157427.7)

### Contributors
* Pu Liu
* Zong Yang
* Ruige Lee

## 图片


## 视频
* 请参考作品视频链接，视频看起来不那么鲜艳
* [风火轮原型版本](https://v.qq.com/x/page/k0127j38gix.html?)
* [风火轮比赛版本](https://v.youku.com/v_show/id_XMzc3ODE3ODQxNg==.html?spm=a2hzp.8244740.0.0)
* [真彩点阵](http://v.youku.com/v_show/id_XMzc3ODE3NDk5Mg==.html?spm=a2h3j.8428770.3416059.1)


