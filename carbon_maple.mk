$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

# Inherit device configuration
$(call inherit-product, device/sony/maple/device.mk)

### BOOTANIMATION
# vendor/lineage/config/common_full_phone.mk
TARGET_SCREEN_HEIGHT := 1920
TARGET_SCREEN_WIDTH := 1080
# vendor/lineage/config/common.mk
TARGET_BOOTANIMATION_HALF_RES := true

### Carbon
$(call inherit-product, vendor/carbon/config/gsm.mk)
$(call inherit-product, vendor/carbon/config/common.mk)

## Device identifier. This must come after all inclusions
PRODUCT_NAME := carbon_maple
PRODUCT_DEVICE := maple
PRODUCT_BRAND := Sony
PRODUCT_MODEL := G8141
PRODUCT_MANUFACTURER := Sony

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_NAME=maple \
    BUILD_FINGERPRINT=Sony/maple/maple:8.0.0/OPR6.170623.013/1:user/dev-keys

PRODUCT_PROPERTY_OVERRIDES += \
    ro.carbon.maintainer="Myself5"
