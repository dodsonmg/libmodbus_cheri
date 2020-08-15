#ifndef _MODBUS_CHERI_H_
#define _MODBUS_CHERI_H_

#include <stdio.h>

/* For CHERI */
#ifndef __has_feature
#define __has_feature(x) 0
#endif

#if !__has_feature(capabilities)
#warning libmodbus_cheri only provides a pass-through if CHERI capabilities are not supported
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
modbus_mapping_t* modbus_mapping_new_start_address_cheri(
    modbus_t *ctx,
    unsigned int start_bits, unsigned int nb_bits,
    unsigned int start_input_bits, unsigned int nb_input_bits,
    unsigned int start_registers, unsigned int nb_registers,
    unsigned int start_input_registers, unsigned int nb_input_registers);

int modbus_preprocess_request_cheri(modbus_t *ctx, uint8_t *req, modbus_mapping_t *mb_mapping);
int modbus_preprocess_request_cheri_baseline(modbus_t *ctx, uint8_t *req, modbus_mapping_t *mb_mapping);

#endif /* _MODBUS_CHERI_H_ */
