//RGB Representations of the visible spectrum.
//Values shift from red (645nm) violet (400nm)
//every 41st value has been commented out so that the total number of values
//is 240, making it more divisible by 12, 24 and 60.
//FROM: http://www.uvm.edu/~kspartal/Physlets/Lecturedemo/LambdaToRGB.html

struct RGB {
  byte r;
  byte g;
  byte b;
};

RGB color12h[] = {
{255, 0, 0}, //645
{255, 99, 0}, //625
{255, 173, 0}, //605
{255, 213, 0}, //593
{255, 255, 0}, //580
{185, 255, 0}, //557
{105, 255, 0}, //533
{0, 169, 255}, //470
{0, 70, 255}, //450
{84, 0, 255}, //425
{118, 0, 237}, //415
{131, 0, 181}, //400
};

RGB color24h[] = {
{255, 0, 0}, //645
{255, 0, 0}, //645
{255, 57, 0}, //635
{255, 99, 0}, //625
{255, 137, 0}, //615
{255, 173, 0}, //605
{255, 193, 0}, //599
{255, 213, 0}, //593
{255, 233, 0}, //587
{255, 242, 0}, //584
{255, 255, 0}, //580
{237, 255, 0}, //574
{219, 255, 0}, //568
{185, 255, 0}, //557
{146, 255, 0}, //545
{105, 255, 0}, //533
{45, 255, 0}, //518
{0, 169, 255}, //470
{0, 123, 255}, //460
{0, 70, 255}, //450
{17, 0, 255}, //438
{84, 0, 255}, //425
{118, 0, 237}, //415
{129, 0, 207}, //407
{131, 0, 181}, //400
};

RGB colorMinSec[] = {
{255, 0, 0}, //645
{255, 27, 0}, //641
{255, 43, 0}, //638
{255, 57, 0}, //635
{255, 79, 0}, //630
{255, 99, 0}, //625
{255, 119, 0}, //620
{255, 137, 0}, //615
{255, 155, 0}, //610
{255, 166, 0}, //607
{255, 183, 0}, //602
{255, 203, 0}, //596
{255, 213, 0}, //593
{255, 223, 0}, //590
{255, 233, 0}, //587
{255, 242, 0}, //584
{255, 249, 0}, //582
{255, 255, 0}, //580
{249, 255, 0}, //578
{243, 255, 0}, //576
{234, 255, 0}, //573
{219, 255, 0}, //568
{204, 255, 0}, //563
{185, 255, 0}, //557
{166, 255, 0}, //551
{146, 255, 0}, //545
{136, 255, 0}, //542
{126, 255, 0}, //539
{115, 255, 0}, //536
{105, 255, 0}, //533
{90, 255, 0}, //529
{66, 255, 0}, //523
{45, 255, 0}, //518
{15, 255, 0}, //512
{0, 255, 40}, //508
{0, 255, 84}, //505
{0, 255, 123}, //502
{0, 213, 255}, //480
{0, 192, 255}, //475
{0, 169, 255}, //470
{0, 146, 255}, //465
{0, 123, 255}, //460
{0, 113, 255}, //458
{0, 97, 255}, //455
{0, 70, 255}, //450
{0, 53, 255}, //447
{0, 34, 255}, //444
{0, 11, 255}, //441
{40, 0, 255}, //434
{55, 0, 255}, //432
{78, 0, 255}, //428
{97, 0, 255}, //425
{107, 0, 255}, //422
{126, 0, 255}, //420
{146, 0, 248}, //418
{152, 0, 237}, //415
{171, 0, 222}, //411
{183, 0, 207}, //407
{195, 0, 192}, //403
{230, 0, 181}, //400
};
