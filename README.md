# Password-Door-Locking-System





    firstly ,system will ask you to make password for door this password will be stored at EEPROM.

    secondly , main menu will be showed in on LCD. main menu contains 2 choice :

    press on '+':change password

    press on '-': for open door

    thirdly,if you press on '+',system will ask you to enter the current password

    if current password is right,it will ask you to enter the new password and retype new password again .

    if current password is wrong , it will tell you its false password.

    fourthly, if you pressed on '-' system will ask you to enter the current password

    if you try enter wrong password two times consecutive , alarm will work

    if you enter the right password , dc-motor will work in clock wise direction for 10 sec to open door then it will work in anti clock wise direction to close door for 10 sec then dc-motor will stop.

the total project includes 2 projects : MC1 and MC2 (microcontroller avr-ATmega16 is used)

    MC1 is connected to LCD and Keypad,by using keypad you can enter the password LCD guide you what you should do and the result of what you enter .

    MC2 connected to External EEPROM and DC-Motor and Buzzer MC1 send the input data to MC2 , MC2 process the data then decide to work DC MOTOR or buzzer

    this is the simulation of this system ..the simulation is done by using protus https://drive.google.com/file/d/0BxW_WWLZUmFNX195Nkh3ekl3Qms/view?usp=sharing
