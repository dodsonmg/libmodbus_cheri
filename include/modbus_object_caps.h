#ifndef _MODBUS_OBJECT_CAPABILITIES_H_
#define _MODBUS_OBJECT_CAPABILITIES_H_

#include <stdio.h>

/* For CHERI */
#ifdef __CHERI_PURE_CAPABILITY__
#include <cheriintrin.h>
#else
#warning libmodbus_object_capabilities only provides a pass-through if CHERI capabilities are not supported
#endif

/* for modbus */
#include <modbus/modbus.h>
#include <modbus/modbus-helpers.h>

/**
 *  Allocates 5 arrays to store bits, input bits, registers, inputs
 * registers, and a string. The pointers are stored in modbus_mapping structure.
 *
 * The modbus_mapping_new_start_address() function shall return the new allocated
 * structure if successful. Otherwise it shall return NULL and set errno to
 * ENOMEM.
 * */
modbus_mapping_t* modbus_mapping_new_start_address_object_caps(
    modbus_t *ctx,
    unsigned int start_bits, unsigned int nb_bits,
    unsigned int start_input_bits, unsigned int nb_input_bits,
    unsigned int start_registers, unsigned int nb_registers,
    unsigned int start_input_registers, unsigned int nb_input_registers);

int modbus_preprocess_request_object_caps(modbus_t *ctx, uint8_t *req, modbus_mapping_t *mb_mapping);
int modbus_preprocess_request_object_caps(modbus_t *ctx, uint8_t *req, modbus_mapping_t *mb_mapping);

#endif /* _MODBUS_OBJECT_CAPABILITIES_H_ */
