#ifndef CONFIG_H
#define CONFIG_H

#include "zmq.hpp"
#include <SerialisableObject.h>
#include <iostream>
#include <vector>

using namespace std;

class Config : public SerialisableObject{

 friend class boost::serialization::access;

 public:

    Config();

    int receiveFlag;
    int Savemode;

    //trigger
    int triggermode;
    vector<int> LAPPDtoBoard1;
    vector<int> LAPPDtoBoard2;
    unsigned int ACC_ID;

    int ResetSwitchACC;
    int ResetSwitchACDC;
    int SMA;

    //triggersettings
    int ACC_Sign;
    int ACDC_Sign;
    int SELF_Sign;
    int SELF_Enable_Coincidence;
    int SELF_Coincidence_Number;
    int SELF_threshold;

    //ACDC boards
    unsigned int ACDC_mask;

    //PSEC chips for self trigger
    int PSEC_Chip_Mask_0;
    int PSEC_Chip_Mask_1;
    int PSEC_Chip_Mask_2;
    int PSEC_Chip_Mask_3;
    int PSEC_Chip_Mask_4;
    unsigned int PSEC_Channel_Mask_0;
    unsigned int PSEC_Channel_Mask_1;
    unsigned int PSEC_Channel_Mask_2;
    unsigned int PSEC_Channel_Mask_3;
    unsigned int PSEC_Channel_Mask_4;

    //Validation time
    float Validation_Start;
    float Validation_Window;

    //Calibration mode
    int Calibration_Mode;

    //Raw mode
    bool Raw_Mode;

    //Pedestal set value channel
    int Pedestal_channel;
    unsigned int Pedestal_channel_mask;

    //PPS
    unsigned int PPSRatio;
    int PPSBeamMultiplexer;

    bool SetDefaults();
    bool Print();

 private:
 
 template <class Archive> void serialize(Archive& ar, const unsigned int version){

  ar & receiveFlag;
  ar & ACC_ID;
  ar & triggermode;
  ar & LAPPDtoBoard1;
  ar & LAPPDtoBoard2;
  ar & ResetSwitchACC;
  ar & ResetSwitchACDC;
  ar & Savemode;
  ar & SMA;
  ar & ACC_Sign;
  ar & ACDC_Sign;
  ar & SELF_Sign;
  ar & SELF_Enable_Coincidence;
  ar & SELF_Coincidence_Number;
  ar & SELF_threshold;

  //ACDC boards
  ar & ACDC_mask;

  //PSEC chips for self trigger
  ar & PSEC_Chip_Mask_0;
  ar & PSEC_Chip_Mask_1;
  ar & PSEC_Chip_Mask_2;
  ar & PSEC_Chip_Mask_3;
  ar & PSEC_Chip_Mask_4;
  ar & PSEC_Channel_Mask_0;
  ar & PSEC_Channel_Mask_1;
  ar & PSEC_Channel_Mask_2;
  ar & PSEC_Channel_Mask_3;
  ar & PSEC_Channel_Mask_4;

  //Validation time
  ar & Validation_Start;
  ar & Validation_Window;

  //Calibration mode
  ar & Calibration_Mode;

  //Raw mode
  ar & Raw_Mode;

  //Pedestal set value channel
  ar & Pedestal_channel;
  ar & Pedestal_channel_mask;
  
  ar & PPSRatio;
  ar & PPSBeamMultiplexer;
  
 }
 
};

#endif
