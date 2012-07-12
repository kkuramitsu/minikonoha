/****************************************************************************
 * Copyright (c) 2012, the Konoha project authors. All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ***************************************************************************/

#ifndef KONOHA2_LOCAL_H_
#define KONOHA2_LOCAL_H_

#define IS_RootKonohaContext(o)   (kctx == (KonohaContext*)o)

// These functions are local functions in minikonoha binary.
// Don't call from packages directly   (kimio)

kObjectVar** KONOHA_reftail(KonohaContext *kctx, size_t size);
void KONOHA_reftraceObject(KonohaContext *kctx, kObject *o);  // called from MODGC
void KONOHA_freeObjectField(KonohaContext *kctx, kObjectVar *o);       // callled from MODGC

void MODCODE_init(KonohaContext *kctx, KonohaContextVar *ctx);
//void MODCODE_genCode(KonohaContext *kctx, kMethod *mtd, const struct _kBlock *bk);

void MODSUGAR_init(KonohaContext *kctx, KonohaContextVar *ctx);
kstatus_t MODSUGAR_loadscript(KonohaContext *kctx, const char *path, size_t len, kline_t pline);
kstatus_t MODSUGAR_eval(KonohaContext *kctx, const char *script, kline_t uline);

void MODLOGGER_init(KonohaContext *kctx, KonohaContextVar *ctx);
void MODLOGGER_free(KonohaContext *kctx, KonohaContextVar *ctx);
void MODSUGAR_loadMethod(KonohaContext *kctx);




#endif /* KONOHA2_LOCAL_H_ */