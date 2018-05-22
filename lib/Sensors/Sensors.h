#pragma once

#include <Arduino.h>

enum SensorLocation
{
	BOARD_BASE,
	BOARD_URBAN,
	BOARD_AUX
};

enum SensorType
{

	// Base Sensors
	SENSOR_BATT_PERCENT,
	SENSOR_BATT_VOLTAGE,
	SENSOR_BATT_CHARGE_RATE,
	SENSOR_VOLTIN,

	// Urban Sensors
	SENSOR_LIGHT,
	SENSOR_TEMPERATURE,
	SENSOR_HUMIDITY,
	SENSOR_CO,
	SENSOR_CO_HEAT_TIME,
	SENSOR_CO_HEAT_CURRENT,
	SENSOR_CO_HEAT_SUPPLY_VOLTAGE,
	SENSOR_CO_HEAT_DROP_VOLTAGE,
	SENSOR_CO_LOAD_RESISTANCE,
	SENSOR_NO2,
	SENSOR_NO2_HEAT_TIME,
	SENSOR_NO2_HEAT_CURRENT,
	SENSOR_NO2_HEAT_SUPPLY_VOLTAGE,
	SENSOR_NO2_HEAT_DROP_VOLTAGE,
	SENSOR_NO2_LOAD_RESISTANCE,
	SENSOR_NOISE_DBA,
	SENSOR_NOISE_DBC,
	SENSOR_NOISE_DBZ,
	SENSOR_ALTITUDE,
	SENSOR_PRESSURE,
	SENSOR_PRESSURE_TEMP,
	SENSOR_PARTICLE_RED,
	SENSOR_PARTICLE_GREEN,
	SENSOR_PARTICLE_IR,
	SENSOR_PARTICLE_TEMPERATURE,

	// I2C Auxiliary Sensors
	SENSOR_ALPHADELTA_SLOT_1A,
	SENSOR_ALPHADELTA_SLOT_1W,
	SENSOR_ALPHADELTA_SLOT_1_CAL,
	SENSOR_ALPHADELTA_SLOT_2A,
	SENSOR_ALPHADELTA_SLOT_2W,
	SENSOR_ALPHADELTA_SLOT_2_CAL,
	SENSOR_ALPHADELTA_SLOT_3A,
	SENSOR_ALPHADELTA_SLOT_3W,
	SENSOR_ALPHADELTA_SLOT_3_CAL,
	SENSOR_ALPHADELTA_TEMPERATURE,
	SENSOR_ALPHADELTA_HUMIDITY,

	SENSOR_GROOVE_I2C_ADC,

	SENSOR_INA219_BUSVOLT,
	SENSOR_INA219_SHUNT,
	SENSOR_INA219_CURRENT,
	SENSOR_INA219_LOADVOLT,

	SENSOR_WATER_TEMP_DS18B20,
	SENSOR_ATLAS_PH,
	SENSOR_ATLAS_EC,
	SENSOR_ATLAS_EC_SG,
	SENSOR_ATLAS_DO,
	SENSOR_ATLAS_DO_SAT,

	SENSOR_PM_1,
	SENSOR_PM_25,
	SENSOR_PM_10,
	
	SENSOR_SHT31_TEMP,
	SENSOR_SHT31_HUM,

	// Actuators (This is temp)
	SENSOR_GROOVE_OLED,

	SENSOR_COUNT
};

const uint32_t minimal_sensor_reading_interval = 10;
const uint32_t default_sensor_reading_interval = 30;
const uint32_t max_sensor_reading_interval = 86400;		// One day

class OneSensor
{
	public:
		SensorLocation location;
		SensorType type;
		const char *title;
		const char *unit;
		String reading;
		uint32_t lastReadingTime;
		bool valid;
		bool controllable;
		uint8_t id;
		uint32_t interval;
		bool enabled;
		bool defaultEnabled;
		bool busy;

		OneSensor(SensorLocation nLocation, SensorType nType, const char *nTitle, uint8_t nId=0, bool nEnabled=false, bool nControllable=false, const char *nUnit="") {
			location = nLocation;
			type = nType;
			title = nTitle;
			unit = nUnit;
			reading = "none";
			lastReadingTime = 0;
			valid = false;
			controllable = nControllable;
			id = nId;
			interval = default_sensor_reading_interval;
			enabled = nEnabled; 
			defaultEnabled = nEnabled;
			busy = false;
		}
};

class AllSensors
{
	public:

		OneSensor list[SENSOR_COUNT+1] {

			//		SensorLocation 		SensorType 				title 						id		enabled		controllable	unit

			// Base Sensors
			OneSensor { BOARD_BASE, 		SENSOR_BATT_PERCENT,			"Battery", 					10,		true,		false,			"%"},
			OneSensor { BOARD_BASE, 		SENSOR_BATT_VOLTAGE,			"Battery voltage",				0,		false,		false,			"V"},
			OneSensor { BOARD_BASE, 		SENSOR_BATT_CHARGE_RATE,		"Battery charge rate",				0,		false,		false,			"mA"},
			OneSensor { BOARD_BASE, 		SENSOR_VOLTIN,				"Input voltage", 				0,		false,		false,			"V"},

			// Urban Sensors
			OneSensor { BOARD_URBAN, 		SENSOR_LIGHT, 				"Light", 					14,		true,		false,			"Lux"},
			OneSensor { BOARD_URBAN, 		SENSOR_TEMPERATURE, 			"Temperature", 					55,		true,		false,			"C"},
			OneSensor { BOARD_URBAN, 		SENSOR_HUMIDITY,			"Humidity", 					56,		true,		false,			"%"},
			OneSensor { BOARD_URBAN, 		SENSOR_CO, 				"Carbon monoxide", 				16,		true,		true,			"kOhm/ppm"},
			OneSensor { BOARD_URBAN, 		SENSOR_CO_HEAT_TIME, 			"Carbon monoxide heat time",			0,		false,		false,			"sec"},
			OneSensor { BOARD_URBAN, 		SENSOR_CO_HEAT_CURRENT, 		"Carbon monoxide heat current",			0,		false,		false,			"mA"},
			OneSensor { BOARD_URBAN, 		SENSOR_CO_HEAT_SUPPLY_VOLTAGE, 		"Carbon monoxide heat supply voltage",		0,		false,		false,			"mV"},
			OneSensor { BOARD_URBAN, 		SENSOR_CO_HEAT_DROP_VOLTAGE, 		"Carbon monoxide heat drop voltage",		0,		false,		false,			"mV"},
			OneSensor { BOARD_URBAN, 		SENSOR_CO_LOAD_RESISTANCE, 		"Carbon monoxide load resistance",		0,		false,		false,			"Ohms"},
			OneSensor { BOARD_URBAN, 		SENSOR_NO2, 				"Nitrogen dioxide",				15,		true,		true,			"kOhm/ppm"},
			OneSensor { BOARD_URBAN, 		SENSOR_NO2_HEAT_TIME, 			"Nitrogen dioxide heat time",			0,		false,		false,			"sec"},
			OneSensor { BOARD_URBAN, 		SENSOR_NO2_HEAT_CURRENT, 		"Nitrogen dioxide heat current",		0,		false,		false,			"mA"},
			OneSensor { BOARD_URBAN, 		SENSOR_NO2_HEAT_SUPPLY_VOLTAGE, 	"Nitrogen dioxide heat supply voltage",		0,		false,		false,			"mV"},
			OneSensor { BOARD_URBAN, 		SENSOR_NO2_HEAT_DROP_VOLTAGE, 		"Nitrogen dioxide heat drop voltage",		0,		false,		false,			"mV"},
			OneSensor { BOARD_URBAN, 		SENSOR_NO2_LOAD_RESISTANCE, 		"Nitrogen dioxide load resistance",		0,		false,		false,			"Ohms"},
			OneSensor { BOARD_URBAN, 		SENSOR_NOISE_DBA, 			"Noise dBA", 					53,		true,		false,			"dBA"},
			OneSensor { BOARD_URBAN, 		SENSOR_NOISE_DBC, 			"Noise dBC", 					0,		false,		false,			"dBC"},
			OneSensor { BOARD_URBAN, 		SENSOR_NOISE_DBZ, 			"Noise dBZ", 					0,		false,		false,			"dBZ"},
			OneSensor { BOARD_URBAN, 		SENSOR_ALTITUDE, 			"Altitude", 					0,		false,		false,			"M"},
			OneSensor { BOARD_URBAN, 		SENSOR_PRESSURE, 			"Barometric pressure",				58,		true,		false,			"kPa"},
			OneSensor { BOARD_URBAN, 		SENSOR_PRESSURE_TEMP,			"Pressure internal temperature", 		0,		false,		false,			"C"},
			OneSensor { BOARD_URBAN, 		SENSOR_PARTICLE_RED,			"Dust particle Red Channel",	 		0,		false,		false,			},
			OneSensor { BOARD_URBAN, 		SENSOR_PARTICLE_GREEN,			"Dust particle Green Channel",	 		0,		false,		false,			},
			OneSensor { BOARD_URBAN, 		SENSOR_PARTICLE_IR,			"Dust particle InfraRed Channel",	 	0,		false,		false,			},
			OneSensor { BOARD_URBAN, 		SENSOR_PARTICLE_TEMPERATURE,		"Dust particle internal temperature",		0,		false,		false,			"C"},

			// I2C Auxiliary Sensors
			// Alphasense Delta board (3 Gas sensor Slots, + SHT31 Temp-Humidity)
			OneSensor { BOARD_AUX, 			SENSOR_ALPHADELTA_SLOT_1A,		"AlphaDelta 1A",				68,		false,		true,			"mV"},
			OneSensor { BOARD_AUX, 			SENSOR_ALPHADELTA_SLOT_1W,		"AlphaDelta 1W",				67,		false,		true,			"mV"},
			OneSensor { BOARD_AUX, 			SENSOR_ALPHADELTA_SLOT_1_CAL,		"AlphaDelta 1cal",				0,		false,		true,			"ppm"},
			OneSensor { BOARD_AUX, 			SENSOR_ALPHADELTA_SLOT_2A,		"AlphaDelta 2A",				62,		false,		true,			"mV"},
			OneSensor { BOARD_AUX, 			SENSOR_ALPHADELTA_SLOT_2W, 		"AlphaDelta 2W",				61,		false,		true,			"mV"},
			OneSensor { BOARD_AUX, 			SENSOR_ALPHADELTA_SLOT_2_CAL,		"AlphaDelta 2cal",				0,		false,		true,			"ppm"},
			OneSensor { BOARD_AUX, 			SENSOR_ALPHADELTA_SLOT_3A, 		"AlphaDelta 3A",				65,		false,		true,			"mV"},
			OneSensor { BOARD_AUX, 			SENSOR_ALPHADELTA_SLOT_3W, 		"AlphaDelta 3W",				64,		false,		true,			"mV"},
			OneSensor { BOARD_AUX, 			SENSOR_ALPHADELTA_SLOT_3_CAL,		"AlphaDelta 3cal",				0,		false,		true,			"ppm"},
			OneSensor { BOARD_AUX, 			SENSOR_ALPHADELTA_TEMPERATURE, 		"AlphaDelta Temperature", 			79,		false,		false,			"C"},
			OneSensor { BOARD_AUX, 			SENSOR_ALPHADELTA_HUMIDITY, 		"AlphaDelta Humidity",				80,		false,		false,			"%"},

			// Groove I2C ADC
			OneSensor { BOARD_AUX,			SENSOR_GROOVE_I2C_ADC,			"Groove ADC",					0,		false,		false,			"V"},

			// Adafruit INA291 High Side DC Current Sensor
			OneSensor { BOARD_AUX,			SENSOR_INA219_BUSVOLT,			"INA219 Bus voltage",				0,		false,		false,			"V"},
			OneSensor { BOARD_AUX,			SENSOR_INA219_SHUNT,			"INA219 Shunt voltage",				0,		false,		false,			"mV"},
			OneSensor { BOARD_AUX,			SENSOR_INA219_CURRENT,			"INA219 Current",				0,		false,		false,			"mA"},
			OneSensor { BOARD_AUX,			SENSOR_INA219_LOADVOLT,			"INA219 Load voltage",				0,		false,		false,			"V"},

			OneSensor { BOARD_AUX,			SENSOR_WATER_TEMP_DS18B20,		"DS18B20 Water temperature",			42,		false,		false,			"C"},
			OneSensor { BOARD_AUX,			SENSOR_ATLAS_PH,			"Atlas PH",					43,		false,		true,			"pH"},
			OneSensor { BOARD_AUX,			SENSOR_ATLAS_EC,			"Atlas Conductivity",				45,		false,		true,			"uS/cm"},
			OneSensor { BOARD_AUX,			SENSOR_ATLAS_EC_SG,			"Atlas Specific gravity",			46,		false,		true,			},
			OneSensor { BOARD_AUX,			SENSOR_ATLAS_DO,			"Atlas Dissolved Oxygen",			48,		false,		true,			"mg/L"},
			OneSensor { BOARD_AUX,			SENSOR_ATLAS_DO_SAT,			"Atlas DO Saturation",				49,		false,		true,			"%"},

			OneSensor { BOARD_AUX,			SENSOR_PM_1,				"PM 1.0",					73,		false,		false,			"ug/m3"},
			OneSensor { BOARD_AUX,			SENSOR_PM_25,				"PM 2.5",					71,		false,		false,			"ug/m3"},
			OneSensor { BOARD_AUX,			SENSOR_PM_10,				"PM 10.0",					72,		false,		false,			"ug/m3"},

			OneSensor { BOARD_AUX,			SENSOR_SHT31_TEMP,			"External Temperature",				0,		false,		false,			"C"},
			OneSensor { BOARD_AUX,			SENSOR_SHT31_HUM,			"External Humidity",				0,		false,		false,			"%"},
			// Later this will be moved to a Actuators.h file
			// Groove I2C Oled Display 96x96
			OneSensor { BOARD_AUX,			SENSOR_GROOVE_OLED,			"Groove OLED",					0,		false,		false,			},
			OneSensor { BOARD_BASE, 		SENSOR_COUNT,				"Not found",					0,		false,		false,			}

			// Add New Sensor Here!!!

		};

		OneSensor & operator[](SensorType type) {
			return list[type];
		}

		SensorType getTypeFromString(String strIn);

	private:
		uint8_t countMatchedWords(String baseString, String input);

};
