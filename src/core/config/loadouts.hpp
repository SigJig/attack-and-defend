/**
 * All loadouts must inherit from the _BaseLoadout class.
 * 
 * Loadout structure:
 * 	displayName = class display name
 * 	primary[] = {weaponName, silencer, available scopes, mag to use, bipod}
 *  secondary[] = same as above (for launchers etc.)
 * 	handgun[] = same as above without bipod
 * 	vest = classname of vest
 * 	headgear = classname of headgear
 * 	uniform = classname of uniform
 *  team = attacker or defender, "" or undefined for both teams
 * 
 * To make a property attacker/defender sided add a subclass like so:
 * 	class Attacker : _BaseAttacker {
 *    	property = value;	 
 *  };
 *
 * Or, for defender:
 *  class Defender : _BaseDefender {
 *		property = value;
 *	};
 *
 * For example, to add a custom uniform for the attacker side,
 *	class <Loadout> : _BaseLoadout {
 * 		class Attacker : _BaseAttacker {
 *			uniform = "whateverthenameoftheuniformis"
 *	 	};
 * 	};
 */

#define BASE_SCOPES "optic_MRCO", "optic_hamr", "optic_Arco_blk_F"
#define HELMET "H_HelmetSpecB_blk"
#define HAT "H_Cap_Oli_hs"

class _BaseAttacker {
	uniform = "U_B_CTRG_1";
	facewear = "G_Balaclava_TI_blk_F";
};

class _BaseDefender {
	uniform = "U_I_C_Soldier_Para_1_F";
	headgear = HAT;
	facewear = "G_Bandanna_beast";
};

class _BaseLoadout {
	vest = "V_PlateCarrier2_rgr_noflag_F";
	binoculars[] = {"Rangefinder", "", "", "", {}, {}, ""};
	linked[] = {"ItemMap","ItemGPS","ItemRadio","ItemCompass","ItemWatch",""};

	class Attacker : _BaseAttacker {};
	class Defender : _BaseDefender {};
};

class LoadoutsConfig {
	class Settings {
		attackerDefault = "MK_1";
		defenderDefault = "MK_1";
	};
	class Loadouts {
		class MK_1 : _BaseLoadout {
			primary[] = {"srifle_DMR_03_F", "", {BASE_SCOPES}, "20Rnd_762x51_Mag", "bipod_01_F_blk"};
			displayName = "MK-I EMR";
		};
		class MK_18 : _BaseLoadout {
			primary[] = {"srifle_EBR_F", "", {BASE_SCOPES}, "20Rnd_762x51_Mag", "bipod_01_F_blk"};
			displayName = "Mk18 ABR";
		};
		class MK_14 : _BaseLoadout {
			primary[] = {"srifle_DMR_06_olive_F", "", {BASE_SCOPES}, "20Rnd_762x51_Mag", ""};
			displayName = "Mk14";
		};
		class AK12 : _BaseLoadout {
			primary[] = {"arifle_AK12_F", "", {BASE_SCOPES}, "30Rnd_762x39_Mag_F", "bipod_01_F_blk"};
			displayName = "AK12";
		};
		class MXSW_30 : _BaseLoadout {
			primary[] = {"arifle_MX_SW_Black_F", "", {BASE_SCOPES}, "30Rnd_65x39_caseless_mag", ""};
			displayName = "MXSW (30 Rounds)";
		};
		class MXSW_100 : _BaseLoadout {
			primary[] = {"arifle_MX_SW_Black_F", "", {BASE_SCOPES}, "100Rnd_65x39_caseless_mag", ""};
			displayName = "MXSW (100 Rounds)";
		};
		class PrometMR : _BaseLoadout {
			primary[] = {"arifle_MSBS65_Mark_black_F", "", {BASE_SCOPES}, "30Rnd_65x39_caseless_msbs_mag", "bipod_01_F_blk"};
			displayName = "Promet MR";
		};
		class Type115 : _BaseLoadout {
			primary[] = {"arifle_ARX_blk_F", "", {BASE_SCOPES}, "30Rnd_65x39_caseless_green", "bipod_01_F_blk"};
			displayName = "Type 115";
		};
		class Katiba : _BaseLoadout {
			primary[] = {"arifle_Katiba_F", "", {BASE_SCOPES}, "30Rnd_65x39_caseless_green", ""};
			displayName = "Katiba";
		};
		
	};
};