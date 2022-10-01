#ifndef GPS_H_
#define GPS_H_

//Function prototypes for GPS frame parsing
bool GPS_newFrame(uint8_t c);
extern uint8_t GPS_Frame;            // a valid GPS_Frame was detected, and data is ready for nav computation

extern int32_t wrap_18000(int32_t ang);

void FW_NAV(void);
void FW_NavSpeed(void);

void GPS_set_pids(void);
void GPS_SerialInit(void);
uint8_t GPS_Compute(void);
void GPS_reset_home_position(void);
void GPS_set_next_wp(int32_t* lat_to, int32_t* lon_to, int32_t* lat_from, int32_t* lon_from);
void GPS_reset_nav(void);

int32_t get_altitude_error();
void clear_new_altitude();
void force_new_altitude(int32_t _new_alt);
void set_new_altitude(int32_t _new_alt);
int32_t get_new_altitude();
void abort_mission(unsigned char error_code);
void GPS_adjust_heading();
void init_RTH(void);
void check_land(void);

#if defined(I2C_GPS)
uint8_t GPS_NewData(void);
#endif

extern uint32_t wp_distance;
extern int32_t target_bearing;

#if defined (FIXEDWING) && (defined (GPS_SERIAL) || defined(I2C_GPS))
/*****************************************/
/*   Settings for FixedWing navigation   */
/*****************************************/

// Use the Patched I2C GPS for FixedWing and OSD
//#define I2CPATCH
/*
   Values set in GUI.
   Set ABS Target Alt for RTL over home position.
   RTH_Alt is set with (POSR) => D

   for Navigation      (NavR) => P,I & D
   for Altitue.        (ALT)  => P, I &D
*/

#define GPS_UPD_HZ             5     // Set loop time for NavUpdate
#define PITCH_COMP             0.5f  // Compensate throttle relative angle of attack
#define ELEVATORCOMPENSATION   100    // Compensate elevator with % of rollAngle

/* Maximum Limits for controls */
#define GPS_MAXCORR    35     // Degrees banking applied by GPS.
#define GPS_RUDDER     0     //

#define GPS_MAXCLIMB   30     // Degrees climbing . To much can stall the plane.
#define GPS_MAXDIVE    30     // Degrees Diving . To much can overspeed the plane.

#define CLIMBTHROTTLE  1900  // Max allowed throttle in GPS modes.
#define CRUICETHROTTLE 1700   // Throttle to set for cruisespeed.

#define IDLE_THROTTLE   1300  // Lowest throttleValue during Descend
#define SCALER_THROTTLE  8    // Adjust to Match Power/Weight ratio of your model

#define FAILSAFE              // Enable RTH failsafe incl Auto DisARM at home to autoland

#define SAFE_NAV_ALT        50  // Safe Altitude during climbouts Wings Level below this Alt. (ex. trees & buildings..)
#define SAFE_DECSCEND_ZONE  50  // Radius around home where descending is OK
#endif
#endif /* GPS_H_ */
