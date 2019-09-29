/**
 * @Function: core::game::selectZone
 * @Description: Selects the zone for the next round
 *
 * :param object _self: Instance of the game class
 * :param string _zone: Selected zone
 */

params [["_self", objNull, [objNull]], ["_zone", "", [""]]];

private _zoneConfig = missionConfigFile >> "ZonesConfig" >> "Zones" >> _zone;
private _settings = missionConfigFile >> "ZonesConfig" >> "Settings";

if !(isClass _zoneConfig) exitWith {false};

private _position = getArray (_zoneConfig >> "position");
private _displayName = (getText (_zoneConfig >> "displayName")) call core(handleString);
private _radius = [_zoneConfig >> "radius", 50] call core(configGet);

private _color = [_settings >> "markerColor", "COLORGREEN"] call core(configGet);
private _type = [_settings >> "marker", "mil_triangle"] call core(configGet);

private _marker = createMarker [configName _zoneConfig, _position];
_marker setMarkerColor _color;
_marker setMarkerType _type;

private _areaMarker = createMarker ["area_" + configName _zoneConfig, _position];
_areaMarker setMarkerSize [_radius, _radius];
_areaMarker setMarkerShape "ELLIPSE";
_areaMarker setMarkerBrush "SolidBorder";
_areaMarker setMarkerColor _color;

_self setVariable ["zone", _zone, true];
_self setVariable ["zoneAreaMarker", _areaMarker, true];

true