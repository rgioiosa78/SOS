/* -*- C -*-
 *
 * Copyright 2011 Sandia Corporation. Under the terms of Contract
 * DE-AC04-94AL85000 with Sandia Corporation, the U.S.  Government
 * retains certain rights in this software.
 *
 * Copyright (c) 2018 Intel Corporation. All rights reserved.
 * This software is available to you under the BSD license.
 *
 * This file is part of the Sandia OpenSHMEM software package. For license
 * information, see the LICENSE file in the top level directory of the
 * distribution.
 *
 */

#include "shmem_internal.h"
#include "transport.h"

#ifdef ENABLE_PROFILING
#include "pshmem.h"

#pragma weak shmem_pcntr_get_pending_put = pshmem_pcntr_get_pending_put
#define shmem_pcntr_get_pending_put pshmem_pcntr_get_pending_put

#pragma weak shmem_pcntr_get_pending_get = pshmem_pcntr_get_pending_get
#define shmem_pcntr_get_pending_get pshmem_pcntr_get_pending_get

#pragma weak shmem_pcntr_get_fi_put = pshmem_pcntr_get_fi_put
#define shmem_pcntr_get_fi_put pshmem_pcntr_get_fi_put

#pragma weak shmem_pcntr_get_fi_get = pshmem_pcntr_get_fi_get
#define shmem_pcntr_get_fi_get pshmem_pcntr_get_fi_get

#pragma weak shmem_pcntr_get_fi_target = pshmem_pcntr_get_fi_target
#define shmem_pcntr_get_fi_target pshmem_pcntr_get_fi_target

#endif /* ENABLE_PROFILING */

void SHMEM_FUNCTION_ATTRIBUTES 
shmemx_pcntr_get_pending_put(shmem_ctx_t ctx, uint64_t *cntr_value)
{
    SHMEM_ERR_CHECK_INITIALIZED();
    *cntr_value = shmem_transport_get_pending_put_cntr((shmem_transport_ctx_t *) ctx);
    return;
}

void SHMEM_FUNCTION_ATTRIBUTES 
shmemx_pcntr_get_pending_get(shmem_ctx_t ctx, uint64_t *cntr_value)
{
    SHMEM_ERR_CHECK_INITIALIZED();
    *cntr_value = shmem_transport_get_pending_get_cntr((shmem_transport_ctx_t *) ctx);
    return;
}

void SHMEM_FUNCTION_ATTRIBUTES 
shmemx_pcntr_get_completed_put(shmem_ctx_t ctx, uint64_t *cntr_value)
{
    SHMEM_ERR_CHECK_INITIALIZED();
    *cntr_value = shmem_transport_get_fi_put_cntr((shmem_transport_ctx_t *) ctx);
    return;
}

void SHMEM_FUNCTION_ATTRIBUTES 
shmemx_pcntr_get_completed_get(shmem_ctx_t ctx, uint64_t *cntr_value)
{
    SHMEM_ERR_CHECK_INITIALIZED();
    *cntr_value = shmem_transport_get_fi_get_cntr((shmem_transport_ctx_t *) ctx);
    return;
}

void SHMEM_FUNCTION_ATTRIBUTES
shmemx_pcntr_get_completed_target(shmem_ctx_t ctx, uint64_t *cntr_value)
{
    SHMEM_ERR_CHECK_INITIALIZED();
    *cntr_value = shmem_transport_get_fi_target_cntr((shmem_transport_ctx_t *) ctx);
    return;
}

