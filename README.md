# Bassein
Bassein, Arduino, Flprog

Лицензия

Проект свободен для некоммерческого использования и исключительно в личных целях. Любое другое использование, например, встраивание любой части кода в коммерческий продукт, распространение любой части исходных кодов на сторонних ресурсах без разрешения автора проекта - не допускается. Все права интеллектуальной собственности на любую программную часть продукта принадлежат их авторам, использование программного кода в сторонних проектах без согласия авторов и упоминания об исходном авторстве - не допускается.

Автор проекта оставляет за собой право в любой момент пересмотреть лицензию распространения продукта.

Файл проекта автоматизации обслуживания бассейна с поддержкой modbus. и RemoteXY

написано в программе Flprog 

адрес Flprog http://flprog.ru 

адрес remoteXY  http://remotexy.com/ru

Файлы 

В ПЛАНАХ

Bassein_final_Modbass_tcp

добавить управления светом
добавить дозировка PH 


Bassein_final_Modbass_tcp (проэкт работающий с modbus tcp)

ИЗМЕНЕНИЯ

 Bassein_final_Modbass_tcp_v_1.1
 
 добавлены максимальная и менимальная температуры за сутки
 добавленна кнопеа принудительного включения насоса на 15 минут
 
 


Bassein_final_remoteXY_v1.3  (проэкт работающий c remoteXY)

Функции контроллера 

1) управление фильтрационным насосом по времени

2 )управление дозированием жидкого хлора в литрах за сутки (добовление каждый час в зависимости от настроек)

3) мониторинг температурв в бассейне и на улице

3) сенсор уровня воды в перелевном баке

компоненты используемые в проекте 

Arduino 2560 MEGA2560 R3   http://hz.ru.aliexpress.com/item/MEGA-2560-R3-ATmega2560-R3-AVR-USB-board-for-Arduino-2560-MEGA2560-R3-NO-USB/32222306768.html?spm=2114.13010608.0.124.MxHJ75

HC-06 Bluetooth   http://hz.ru.aliexpress.com/item/Bluetooth-pass-through-modules-with-universal-mounting-with-Enable-and-state-output-wireless-serial-from-machine/658943620.html?spm=2114.13010608.0.113.Gklkpc

Dc 12 В D4  насос-дозатор   http://hz.ru.aliexpress.com/item/DC-12V-D4-Lab-Dosing-Pump-Peristaltic-Head-Chemical-Water-Liquid-Analysis/32357604600.html

DS18b20   http://hz.ru.aliexpress.com/item/DS18B20-Stainless-steel-package-1-meters-waterproof-DS18b20-temperature-probe-temperature-sensor-18B20-in-stock-high/1622159040.html?spm=2114.03020208.3.11.d5xzkN&ws_ab_test=searchweb201556_10,searchweb201602_4_10048_10047_10017_10046_10045_406,searchweb201603_11&btsid=342cd35c-a6c1-4ec8-884c-10d7adcf83a4

соединительные провода   http://hz.ru.aliexpress.com/item/Male-to-Male-Color-Breadboard-Cable-Jump-Wire-Jumper-For-Arduino-Shield-40pcs-20cm-2-54mm/32255218972.html?spm=2114.13010608.0.90.ofphsL

реле    http://hz.ru.aliexpress.com/item/1-Channel-5V-Relay-Module-Low-level-for-SCM-Household-Appliance-Control-FREE-SHIPPING-For-Arduino/1617716706.html?spm=2114.13010608.0.133.ofphsL

W5100     http://hz.aliexpress.com/snapshot/3006648155.html?orderId=30150190959308

часы DS1307  http://hz.ru.aliexpress.com/item/5PCS-DS3231-AT24C32-IIC-RTC-Clock-Timer-Memory-Module-For-Arduino-Replace-DS1307/1864985742.html?spm=2114.03020208.3.148.0CKS7V&ws_ab_test=searchweb201556_10,searchweb201602_4_10048_10047_10017_10046_10045_406,searchweb201603_11&btsid=fffffde1-a557-438d-aaef-e14610dc2057

ПРОШЛЫЕ ВЕРСИИ

Bassein_final_Modbass_tcp_v_1

