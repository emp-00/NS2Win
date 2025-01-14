; +++ This file contains NS2Win user specific settings +++ 
; Source: https://github.com/emp-00/NS2Win/
; Author: Marco Krueger
; NS2Win displays your current glucose with delta, trend direction, IOB+COB via the Nightscout PEBBLE api incl. token authentification
; License: Creative Commons Attribution-NonCommercial-ShareAlike 4.0
; Important: In order to apply any changes please save this file and then refresh your running NS2Win skin (right click -> Refresh skin)
[Variables]

; +++ SKIN SCALE FACTOR +++
; Overall skin scale: standard factor 1.00 = 100% size (developed for 1920x1200px); change to e.g. 1.50 = 150% for high dpi screens or 0.95 = 95% size
Scale=1.00

; +++NIGHTSCOUT URL AND TOKEN+++
; Adjust your NightScout BASE URL here. Example: https://my-nightscout-site.herokuapp.com/ **make sure to include the trailing '/'**
NightScoutURL=https://[CHANGE-YOUR-NIGHTSCOUT-URL]/

; Nightscout TOKEN, required if your nightscout instance is running with 'export AUTH_DEFAULT_ROLES="denied"' (recommended!)
; If your nightscout instance is running with AUTH_DEFAULT_ROLES="readable" ("open to the world", not recommended!) set 'NightScoutToken=' thus leave string empty!
; General official information around Nightscout data security: https://nightscout.github.io/nightscout/security/
; Simple instructions HOWTO create a TOKEN for your nightscout instance: https://nightscout.github.io/nightscout/security/#create-authentication-tokens-for-users
; When using TOKEN variable: make sure to always start the string with "?token="[YOUR TOKEN] !!
NightScoutToken=?token=[CHANGE-YOUR-TOKEN]

; +++ALARM THRESHOLDS, COLORS AND OTHER ADVANCED SETTINGS+++
; Low/High threshold values for red/orange signal "alarm colors" in mg/dl
LowGlucoseAlert=70
HighGlucoseAlert=160
; Stale data alert: notify with strikethrough output after XX minutes of "no data reception" = signal loss = stale data; this variable is in MINUTES
StaleGlucoseAlertMinutes=15
; Variables for skin background: ColorBg (R,G,B - range 0..255): black default=0,0,0 & subtle transparency default BgAlpha=220 (0..255)
ColorBg=0,0,0
BgAlpha=220
; Color of regular/white/red/orange/yellow/green text meters (R,G,B,Transparency - rage 0..255): ColorText default=220,220,220,255 (light grey, no transparency)
ColorText=220,220,220,255
ColorWhite=250,250,250,255
ColorRed=255,0,0,255
ColorOrange=255,155,0,255
ColorYellow=255,255,0,255
ColorGreen=125,255,0,255
; Color "Ticking time" meter min:secs meter in top right corner: default=200,250,255,255 (light blue); If desired -> Hide meter=0,0,0,0
ColorTicking=200,250,255,255
; Threshold values for trend arrow: T1 = 45up/down; T2 = 90up/down; T3 = double-up/down; recommended for Dexcom G6 (values every 5 mins): T1=2, T2=7, T3=11
; Note: We need negative (d=down) and positive (u=up) values separately (Rainmeter treats variables as strings thus multiplication (-1)*#Delta# does not work in IfConditions)
DeltaT3d=-11
DeltaT2d=-7
DeltaT1d=-2
DeltaT1u=2
DeltaT2u=7
DeltaT3u=11
; IOB and COB high threshold values for yellow "signal colors"; IOB/COB = Insulin/Carbs on Board
HighIOB=10
HighCOB=90