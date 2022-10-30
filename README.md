# NS2Win
 Rainmeter skin to display your Nightscout glucose on your Windows device using Rainmeter.
 
 This desktop gadget requires Rainmeter: https://www.rainmeter.net
 
 Customized Design and New Features:
 - Based on the initial release of MrJordanRoth Rev. 1.0.0 
 - Can be used with all CGM's e.g. Dexcom G5, G6, G7, Abbott FreeStyle Libre with Nightscout-uploader e.g. via xDrip+
 - Rounded corner design based on SilverAzide Gadgets suite "Solid background2"
 - Customized High/Low Alarm values for colorized glucose, delta glucose +/- XX mg/dl colored
 - "Ticking" time in right corner showing time difference current system time vs. last glucose reading
 - Preparation for "5 min" polling e.g. shortly after 5 mins have passed (e.g. Dexcom G6); default = 1 min polling
  
 ![image](https://user-images.githubusercontent.com/60714349/198889996-0fb75f12-c352-4ff4-bfc9-f3e5ff6542d3.png)
 ![image](https://user-images.githubusercontent.com/60714349/198890172-a5d5af8b-0b2e-4207-8283-d1bd90fd9c19.png)
 ![image](https://user-images.githubusercontent.com/60714349/198889055-e20f2d5d-10e9-4174-b067-a61dc046032a.png)
 ![image](https://user-images.githubusercontent.com/60714349/198889087-de531893-340b-4562-99d2-1a6f4f8de67c.png)
 
 Update V1.1.0 @2022-10-05 MK
 - Original pebble API call only worked with --> AUTH_DEFAULT_ROLES="readable" (thus not usable with: export AUTH_DEFAULT_ROLES="denied")
 - However, the pebble-api call also works with tokens (set up via Admin Tools): https://[YOUR-NIGHTSCOUT-URL]/pebble?token=[YOUR-TOKEN]
 
 Update V1.1.1 @2022-10-07 MK
 - Modified [meterDeltaDirection] with additional code split in [measure]-section to display positive delta values with leading "+"
 - Modified/optimized meter X/Y size, added vertical separator line and some minor code readability changes
 
 Update V1.1.2 @2022-10-09 MK
 - Removed [cUpdate] section !Refresh'ing every minute (with logfile entry!); instead using UpdateRate=60 for Webparser, same effect but "clean solution"
 - Removed [MeasureMinutes2Milliseconds] including into StaleData formula and DynamicVariable/!Redraw improvements
 
 Update V1.2.0 @2022-10-12 MK
 - Added X min ago display and various code simplifications/improvements incl. TimeZone/DaylightSavings client vs UTC servertime delta
 - Added X.X min "ticking" time difference last glucose on server vs. client time as preparation for 5 min polling
 - Updated small improvements from first 5 min polling attempts (1.1.5a) but reverted to 1 min polling due stability issues, Revision set to 1.2.0
 - Remaining improvement potential: Sync Webparser call via Trigger //IfTrueAction2=[!CommandMeasure MeasureSite "Update"]// if time delta >5.X <5.5 mins
 
 Update V1.2.5 @2022-10-15 MK
 - Fixed color change bug "lucky 100" rainbow color not going away with smart IfCondition4 incl. InlineSetting="" and OnUpdateAction change
 - Added IfCondition3=CalcGlucoseDelta = 0 to make sure "delta 0" is colored grey and NOT red or green, now all conditions are covered
 - Various color fixes e.g. fixing display of ticking minutes with more than 2 digits
 - Added "Solid background2" with rounded edges, adapted from SilverAzide Gadgets 7.4.0 suite and removed BackgroundMode=2 SolidColor
 
 Update V1.2.6 @2022-10-29 MK
 - Commented out [MeasureDeltaDirection] displaying "Flat" most of the time due to xDrip/NS-bug
 - Added [CalcAverageDeltaDirection] using the "sum of last 3 deltas" to calculate own trend arrow based own trigger values and added arrow coloring
