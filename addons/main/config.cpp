#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_main"};
        author = "cineafx";
        authorUrl = "https://github.com/cineafx";
        VERSION_CONFIG;
    };
};

#define ICON_CHECKED QUOTE(\a3\ui_f\data\gui\RscCommon\RscCheckBox\CheckBox_checked_ca.paa)
#define ICON_UNCHECKED QUOTE(\a3\ui_f\data\gui\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa)
#define CURATOR_SELECTED_ALLVEHICLES ((curatorSelected select 0) select {(_x isKindOf 'AllVehicles') && !(_x isKindOf 'Man')})

class ACE_ZeusActions {
  class ZeusUnits {
    class GVAR(vehicle_optics_nv_disable) { // disable NV
      displayName = "Night vision";
      condition = QUOTE({equipmentDisabled _x select 0 == false} count CURATOR_SELECTED_ALLVEHICLES  > 0);
      statement = QUOTE({_x disableNVGEquipment true} forEach CURATOR_SELECTED_ALLVEHICLES);
      icon = ICON_UNCHECKED;
    };
    class GVAR(vehicle_optics_nv_reenable) { // reenable NV
      displayName = "Night vision";
      condition = QUOTE({equipmentDisabled _x select 0 == true} count CURATOR_SELECTED_ALLVEHICLES  > 0);
      statement = QUOTE({_x disableNVGEquipment false} forEach CURATOR_SELECTED_ALLVEHICLES);
      icon = ICON_CHECKED;
    };
  };
};
