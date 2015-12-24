/*
IMPORTANT NOTE about TembooAccount.h

TembooAccount.h contains your Temboo account information and must be included
alongside your sketch. To do so, make a new tab in Arduino, call it TembooAccount.h,
and copy this content into it. 
*/

#define TEMBOO_ACCOUNT "***ACCOUNT_NAME_GOES_HERE***"  // Your Temboo account name 
#define TEMBOO_APP_KEY_NAME "***APP_KEY_NAME_GOES_HERE***"  // Your Temboo app key name
#define TEMBOO_APP_KEY "***SECRET_KEY_GOES_HERE***"  // Your Temboo app key

/* 
The same TembooAccount.h file settings can be used for all Temboo SDK sketches.  
Keeping your account information in a separate file means you can share the 
main .ino file without worrying that you forgot to delete your credentials.
*/
