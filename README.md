# NS2Win_MK
 
 NS2Win_MK 1.3.0: Rainmeter skin to display Nightscout glucose readings on your Windows device.

Nightscout is used by many diabetics for CGM blood glucose monitoring: http://www.nightscout.info

- This desktop gadget requires Rainmeter: https://www.rainmeter.net
- HowTo setup: Download rmskin installer, use Settings Button to edit UserVariables.inc and enter your Nightscout URL and Token
- Additional alarm threshold and advanced configuration options available (only if interested/needed)

Screenshots:

![NS2Win_1 3 0-teaser](https://user-images.githubusercontent.com/60714349/204150482-2bc529da-d52c-4920-a354-eb144d1cb0ac.png)

Customized Design and New Features:

- Can be used with all CGM's e.g. Dexcom G5, G6, G7, Abbott FreeStyle Libre with Nightscout-uploader e.g. via xDrip+
- Showing blood glucose, time since last reading, delta, arrow, IOB and COB
- Customized High/Low Alarm values for colorized glucose, delta glucose +/- XX mg/dl colored
- "Ticking" time in right corner showing time difference current system time vs. last glucose reading, switch off if not needed
- Rounded corner design based on SilverAzide Gadgets suite "Solid background2" and full skin scaling high dpi functionality
 
 ![NS2Win_1 3 0-teaser](https://user-images.githubusercontent.com/60714349/204150346-db58d3aa-4ac9-4086-881a-a24cfc30e266.png)

Changelog History:

Original V1.0.0 by Jordan Roth: https://github.com/MrJordanRoth/NS2Win

Update V1.1.0 to 1.1.2 @2022-10-05 to 10-09 MK
- Note: Original pebble API call only worked with --> AUTH_DEFAULT_ROLES="readable", thus was not usable with: export AUTH_DEFAULT_ROLES="denied"
- Added Nigtscout token functionality for enabling using secure AUTH_DEFAULT_ROLES="denied" nightscout configurations
- Modified [meterDeltaDirection] with additional code split in [measure]-section to display positive delta values with leading "+"
- Removed [cUpdate] section doing a !Refresh every minute (with logfile entry!); instead using UpdateRate=60 in the Webparser section, same effect but "clean solution"
- Removed [MeasureMinutes2Milliseconds] incorporated directly into StaleData formula and DynamicVariable / !Redraw improvements; preparation for 5 min event driven api call

Update V1.2.0 @2022-10-12 MK
- Added X min ago display and various code simplifications/improvements incl. timezone/daylightsavings client vs UTC servertime delta
- Added X.X min "ticking" time difference last glucose on server vs. client time as preparation for 5 min polling
- Various improvements from first 5 min polling attempts (1.1.5a) but reverted to 1 min polling due stability issues, Revision set to 1.2.0
- Remaining improvement potential: Sync Webparser call via Trigger //IfTrueAction2=[!CommandMeasure MeasureSite "Update"]// if time delta >5.X <5.5 mins

Update V1.2.5 @2022-10-15 MK
- Fixed IfCondition3=CalcGlucoseDelta = 0 to make sure "delta 0" is colored grey and NOT red or green, now all conditions are covered
- Fixed various color issues e.g. "lucky 100" rainbow color not going away and fixed display of ticking minutes with more than 2 digits
- Added "Solid background2" with rounded edges for the skin, adapted from SilverAzide Gadgets 7.4.0 suite and removed BackgroundMode=2 SolidColor

Update V1.2.6 @2022-10-29 MK -- release uploaded to https://github.com/emp-00/NS2Win/
- Added calculation of "sum of last 3 deltas" to calculate own trend arrow and removed [MeasureDeltaDirection] displaying mostly "Flat" due to xDrip/NS-bug

Update V1.3.0 @2022-11-26 MK -- release uploaded to https://github.com/emp-00/NS2Win/
- Added IOB and COB to RegExp and added display of these two values with two additional meters, total gadget width increased accordingly
- Fixed issue by adding [!SetVariable GlucoseDelta0+1+2 "0"] bang to IfCondition=MeasureTimeDifferenceMinutes>#StaleGlucoseAlertMinutes# deleting last deltas before signal loss
- Changed the ticking time display from decimal e.g. 3.8 min to "3:50" with modulus/floor calcs; can be easily adjusted to rounding to e.g 15 secs if liked better
- Improved WebParser RegExp robustness for pebble API: using look-ahead assertion sub-string functionality, now working with different NS configurations e.g. without COB/IOB
- Added user specific settings file "Uservariables.inc", nightscout server URL/token, alarm+arrow thresholds, colors and skin scale factor (right click -> Change NS2Win settings)
- Added "Settings button" only showing in left top corner when hovering over the skin, adapted from SilverAzide's Gadgets 7.4.0 suite
- Added option to configure color of the "Ticking Time" meter in user settings and thus if desired, this meter can be disabled by setting the color to the background color
- Added automatic error message display with separate meter and [ErrorCounter] measure, separately for Nightscout URL/token misconfiguration or network error/dropouts
- Added Tooltips for normal running mode and for error message meter showing Nightscout URL/Token and instructions how to change settings
- Compressed total skin width by changeover to Calibri font, changed font sizes and pixel-by-pixel optimized overall layout
- Added full skin scaling functionality e.g. for high dpi screens with scale factor e.g. 1.55 = 155% with TransformationMatrix styles (thanks to Xanxi)
