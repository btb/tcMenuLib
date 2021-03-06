#ifndef _TCMENU_FIXTURES_H_
#define _TCMENU_FIXTURES_H_


const PROGMEM AnalogMenuInfo minfoAnalogSub = { "SubAnalog", 10, 20, 255, NO_CALLBACK, 0, 1, "SU" };
AnalogMenuItem menuSubAnalog(&minfoAnalogSub, 0, NULL);

const PROGMEM SubMenuInfo minfoSub = { "Settings", 7, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackSub(&menuSubAnalog, (const AnyMenuInfo*)&minfoSub);
SubMenuItem menuSub(&minfoSub, &menuBackSub, NULL);

const PROGMEM AnalogMenuInfo minfoAnalog = { "Analog", 1, 2, 255, NO_CALLBACK, 0, 1, "AB" };
AnalogMenuItem menuAnalog(&minfoAnalog, 0, &menuSub);

const PROGMEM AnalogMenuInfo minfoAnalog2 = { "Analog2", 2, 4, 100, NO_CALLBACK, 0, 10, "" };
AnalogMenuItem menuAnalog2(&minfoAnalog2, 0, &menuAnalog);

const char enumStrItem1[] PROGMEM = "ITEM1";
const char enumStrItem2[] PROGMEM = "ITEM2";
const char enumStrItem3[] PROGMEM = "ITEM3";
const char* const enumStrPort2Dir[] PROGMEM  = { enumStrItem1, enumStrItem2, enumStrItem3 };
const PROGMEM EnumMenuInfo minfoEnum1 = { "Enum1", 3, 6, 2, NO_CALLBACK , enumStrPort2Dir };
EnumMenuItem menuEnum1(&minfoEnum1, false, &menuAnalog2);

const PROGMEM BooleanMenuInfo boolMenu1 = {"Bool1", 4, 8, 1, NO_CALLBACK, NAMING_TRUE_FALSE };
BooleanMenuItem boolItem1(&boolMenu1, false, &menuEnum1);

const PROGMEM TextMenuInfo minfoText1 = {"Text1", 5, 9, 10, NO_CALLBACK };
TextMenuItem textMenuItem1(&minfoText1, &boolItem1);

#endif // defined