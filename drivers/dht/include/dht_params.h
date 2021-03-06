/*
 * Copyright (C) 2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_dht
 *
 * @{
 * @file
 * @brief       Default configuration for DHT devices
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef DHT_PARAMS_H
#define DHT_PARAMS_H

#include "board.h"
#include "dht.h"
#include "saul_reg.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Set default configuration parameters for the DHT devices
 * @{
 */
#ifndef DHT_PARAM_PIN
#define DHT_PARAM_PIN               (GPIO_PIN(0, 0))
#endif
#ifndef DHT_PARAM_TYPE
#define DHT_PARAM_TYPE              (DHT11)
#endif
#ifndef DHT_PARAM_PULL
#define DHT_PARAM_PULL              (GPIO_IN_PU)
#endif

#define DHT_PARAMS_DEFAULT          {.pin     = DHT_PARAM_PIN, \
                                     .type    = DHT_PARAM_TYPE, \
                                     .in_mode = DHT_PARAM_PULL}
/**@}*/

/**
 * @brief   Configure DHT devices
 */
static const dht_params_t dht_params[] =
{
#ifdef DHT_PARAMS_BOARD
    DHT_PARAMS_BOARD,
#else
    DHT_PARAMS_DEFAULT,
#endif
};

/**
 * @brief   Get the number of configured DHT devices
 */
#define DHT_NUMOF       (sizeof(dht_params) / sizeof(dht_params[0]))

#ifdef MODULE_SAUL_REG
/**
 * @brief   Allocate and configure entries to the SAUL registry
 */
static const saul_reg_info_t dht_saul_info[][2] =
{
    {
        { .name = "dht-temp" },
        { .name = "dht-hum" }
    }
};
#endif

#ifdef __cplusplus
}
#endif

#endif /* DHT_PARAMS_H */
/** @} */
