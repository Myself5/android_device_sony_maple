/*
 * Copyright (C) 2008 The Android Open Source Project
 * Copyright (C) 2014 The CyanogenMod Project
 * Copyright (C) 2017 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string>
#include <fstream>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#include "vendor_init.h"
#include "property_service.h"

using android::init::property_set;
using android::base::GetProperty;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_dual(char const system_prop[], char const vendor_prop[], char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void target_load_properties()
{

    std::string model = GetProperty("ro.product.vendor.name", "");

    if (model == "G8142") {
            property_override("ro.semc.product.model", "G8142");
            property_override("persist.multisim.config", "dsds");
            property_override("persist.radio.multisim.config", "dsds");
            property_override("ro.telephony.default_network", "9,0");
            property_override("persist.vendor.radio.block_allow_data", "0");
            property_override_dual("ro.product.model", "ro.vendor.product.model", "G8142");
            property_override_dual("ro.product.name", "ro.vendor.product.name", "maple_dsds");
            property_override_dual("ro.product.device", "ro.vendor.product.device", "maple_dsds");
        } else {
            property_override("ro.semc.product.model", "G8141");
            property_override("ro.telephony.default_network", "9");
            property_override("persist.vendor.radio.block_allow_data", "1");
            property_override_dual("ro.product.model", "ro.vendor.product.model", "G8141");
            property_override_dual("ro.product.name", "ro.vendor.product.name", "maple");
            property_override_dual("ro.product.device", "ro.vendor.product.device", "maple");
        }
}
