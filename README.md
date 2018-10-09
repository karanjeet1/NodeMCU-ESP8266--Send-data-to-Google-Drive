# NodeMCU-ESP8266--Send-data-to-Google-Drive
In this project, we can send data from **ESP Module(NodeMCU Base ver 1.0)**, which can be internally processed data or data from any external source.Those data values are then send to anyone's personal Google Drive account in the form of Spreadsheets.

## Installation
1. Log in into your google drive and create a new Blank Spreadsheet.
2. Enter details of the tags into header row, such as: Time, Output1, Output2 and at last save it.
3. Then select Tools->Script editor. A new Script file will be opened, rename it with the same filename that you gave to your Spreadsheet. 
4. Copy the code in the file **"Cloud_scriptfile.txt"** and paste it into your Script file. 
5. Replace sheet_id wriiten in the code by the Sheet ID of your Spreadsheet.
    https://docs.google.com/spreadsheets/d/**<SHEET_ID>**/edit#gid=0
6. Then save your script and select Publish/Deploy as web app. After Deploying, you will got a link like this: https://script.google.com/macros/s/**<SCRIPT_ID>**/exec?
    **NOTE:** Select option Anyone or Anyone, even anonymous.
    	    
7. After this open latest version of **Arduino IDE code(*.ino)** and uplode it in the ESP Module (NodeMCU Base ver 1.0).
8. If you want to take input from any external device then connect that device onto **Pin-D4(GPIO5)**. Otherwise, just send values by using **Send(x,y);**.
