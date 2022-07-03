# Cyberpunk Mask    
一个基于ESP32的赛博朋克面具，通过右上角的菜单和按钮选择左下角屏幕显示的动画，以及控制跑马灯的灯效。

<hr>        

## 文件说明        
- CyberpunkMaskEsp32    
  基于Arduino的ESP-WAROOM-32代码，Boards Manager请安装esp32插件。

- MaskParts     
  solidworks模型文件
  - stl     
    STL格式的模型文件
<hr>

## 开发环境        
- Arduino IDE [1.8.19]      
- Board: esp32 [2.0.2]
  - DOIT ESP32 DEVKIT V1    
  - Upload speed: 921600 (Default)
  - Flash frequency: 80MHz (Default)
- Libraries:        
  - ESP32 Digital RGB LED Drivers [76863da42599f7b082821e4cee0ea00ba23b0918] | https://github.com/MartyMacGyver/ESP32-Digital-RGB-LED-Drivers | WS2812跑马灯带 (安装库的非本次使用的版本，已复制到本项目代码中)      
  - ESP8266 and ESP32 OLED driver for SSD1306 displays [4.3.0]| https://github.com/ThingPulse/esp8266-oled-ssd1306 | SSD1306 OLED I2C屏幕       
  - Time [1.6.1] | Arduino 时间库      
 
<hr>

## 电路图
本次使用的是Goouuu-ESP32，引脚定义如下，可以根据实际芯片的端口调整接线，具体请调整代码中的I/O定义。      
<img src="./draw/circuit_diagram.jpg" width="500px">

## 装配
### 3D打印的零件(TPU打印材料 ￥64/kg)        
- 菜单显示屏固定架(part_menu_frame)：      
<img src="./draw/part_menu_frame.jpg" width="200px">

- 图形显示屏固定架(part_screen_frame)：      
<img src="./draw/part_screen_frame.jpg" width="200px">

- 中间连接器(part_connector)：      
<img src="./draw/part_connector.jpg" width="200px">

- 主板固定架(part_board_cage)：      
<img src="./draw/part_board_cage.jpg" width="200px">

### 购买的零件
- 面具（￥25）      
<img src="./draw/part_mask.jpg" width="200px">

- OLED透明显示屏1.51寸 128*64（SSD1306 ￥56）×2       
<img src="./draw/screen.jpg" width="200px">
<img src="./draw/screen1.jpg" width="200px">

- WS2812B LED灯带 60灯（￥17/m）        
<img src="./draw/led.jpg" width="200px">

- ESP32 ESP-WROOM-32（Goouuu-ESP32 ￥21）     
<img src="./draw/esp32.jpg" width="200px">

- PE波纹管（AD10:￥5/5m,AD21.2：￥5.8/5m）     
<img src="./draw/pip.jpg" width="200px">

- 灯带硅胶外壳（D13*13 ￥10/m）          
<img src="./draw/led_shell.jpg" width="200px">

- 导线若干

### 成品      
<img src="./draw/sample1.jpg" width="200px">
<hr>

## 效果
[![Play on youtube](https://img.youtube.com/vi/BOateCBAd_g/0.jpg)](https://www.youtube.com/embed/BOateCBAd_g)

