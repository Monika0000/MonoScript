#include <mono/mini/mini.h>

const MonoInstSpec mono_amd64_desc [] = {
        {{   0,    0,    0,    0,    0,    0}}, // null entry
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{   0,    0,    0,    0,    0,    0}}, // nop
        {{   0,    0,    0,    0,    1,    0}}, // hard_nop
        {{   0,    0,    0,    0,    2,    0}}, // relaxed_nop
        {{   0,  'i',  'i',    0,    3,    0}}, // compare
        {{   0,  'i',    0,    0, 0x0d,    0}}, // compare_imm
        {{   0,  'f',  'f',    0, 0x0d,  'a'}}, // fcompare
        {{   0,  'f',  'f',    0, 0x0d,  'a'}}, // rcompare
        {{   0,  'i',  'i',    0,    3,    0}}, // lcompare
        {{   0,  'i',  'i',    0,    3,    0}}, // icompare
        {{   0,  'i',    0,    0,    8,    0}}, // icompare_imm
        {{   0,  'i',    0,    0, 0x0d,    0}}, // lcompare_imm
        {{ 'i',  'i',    0,    0,  'x',    0}}, // localloc
        {{ 'i',    0,    0,    0,  'x',    0}}, // localloc_imm
        {{   0,  'b',    0,    0,    5,    0}}, // check_this
        {{   0,    0,    0,    0, 0x2e,  'c'}}, // seq_point
        {{   0,    0,    0,    0,    0,    0}}, // il_seq_point
        {{   0,    0,    0,    0, 0x20,  'c'}}, // voidcall
        {{   0,  'i',    0,    0, 0x20,  'c'}}, // voidcall_reg
        {{   0,  'b',    0,    0, 0x20,  'c'}}, // voidcall_membase
        {{ 'a',    0,    0,    0, 0x20,  'c'}}, // call
        {{ 'a',  'i',    0,    0, 0x20,  'c'}}, // call_reg
        {{ 'a',  'b',    0,    0, 0x20,  'c'}}, // call_membase
        {{ 'f',    0,    0,    0, 0x40,  'c'}}, // fcall
        {{ 'f',  'i',    0,    0, 0x40,  'c'}}, // fcall_reg
        {{ 'f',  'b',    0,    0, 0x40,  'c'}}, // fcall_membase
        {{ 'f',    0,    0,    0, 0x40,  'c'}}, // rcall
        {{ 'f',  'i',    0,    0, 0x40,  'c'}}, // rcall_reg
        {{ 'f',  'b',    0,    0, 0x40,  'c'}}, // rcall_membase
        {{ 'a',    0,    0,    0, 0x40,  'c'}}, // lcall
        {{ 'a',  'i',    0,    0, 0x40,  'c'}}, // lcall_reg
        {{ 'a',  'b',    0,    0, 0x40,  'c'}}, // lcall_membase
        {{   0,    0,    0,    0, 0x40,  'c'}}, // vcall
        {{   0,  'i',    0,    0, 0x40,  'c'}}, // vcall_reg
        {{   0,  'b',    0,    0, 0x40,  'c'}}, // vcall_membase
        {{   0,    0,    0,    0, 0x40,  'c'}}, // vcall2
        {{   0,  'i',    0,    0, 0x40,  'c'}}, // vcall2_reg
        {{   0,  'b',    0,    0, 0x40,  'c'}}, // vcall2_membase
        {{   0,  'i',  'i',    0, 0xc0,  'c'}}, // dyn_call
        {{ 'i',    0,    0,    0, 0x0a,    0}}, // iconst
        {{ 'i',    0,    0,    0, 0x0a,    0}}, // i8const
        {{ 'f',    0,    0,    0, 0x11,    0}}, // r4const
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{ 'f',    0,    0,    0, 0x0c,    0}}, // r8const
        {{ 'i',    0,    0,    0,    0,    0}}, // dummy_iconst
        {{ 'i',    0,    0,    0,    0,    0}}, // dummy_i8const
        {{ 'f',    0,    0,    0,    0,    0}}, // dummy_r8const
        {{ 'f',    0,    0,    0,    0,    0}}, // dummy_r4const
        {{   0,    0,    0,    0,    0,    0}}, // label
        {{   0,  'i',    0,    0, 0x18,    0}}, // throw
        {{   0,  'i',    0,    0, 0x18,    0}}, // rethrow
        {{   0,  'b',    0,    0, 0x0b,    0}}, // arglist
        {{ 'b',  'i',    0,    0,    9,    0}}, // store_membase_reg
        {{ 'b',  'c',    0,    0,    9,    0}}, // storei1_membase_reg
        {{ 'b',  'i',    0,    0,    9,    0}}, // storei2_membase_reg
        {{ 'b',  'i',    0,    0,    9,    0}}, // storei4_membase_reg
        {{ 'b',  'i',    0,    0,    9,    0}}, // storei8_membase_reg
        {{ 'b',  'f',    0,    0, 0x0f,    0}}, // storer4_membase_reg
        {{ 'b',  'f',    0,    0, 0x0a,    0}}, // storer8_membase_reg
        {{ 'b',  'x',    0,    0,    9,    0}}, // storex_membase_reg
        {{ 'b',  'x',    0,    0,    7,    0}}, // storex_aligned_membase_reg
        {{ 'b',  'x',    0,    0,    7,    0}}, // storex_nta_membase_reg
        {{ 'b',    0,    0,    0, 0x0f,    0}}, // store_membase_imm
        {{ 'b',    0,    0,    0, 0x0b,    0}}, // storei1_membase_imm
        {{ 'b',    0,    0,    0, 0x0d,    0}}, // storei2_membase_imm
        {{ 'b',    0,    0,    0, 0x0d,    0}}, // storei4_membase_imm
        {{ 'b',    0,    0,    0, 0x12,    0}}, // storei8_membase_imm
        {{ 'b',  'x',    0,    0,    9,    0}}, // storex_membase
        {{ 'i',  'b',    0,    0,    8,    0}}, // load_membase
        {{ 'c',  'b',    0,    0,    9,    0}}, // loadi1_membase
        {{ 'c',  'b',    0,    0,    9,    0}}, // loadu1_membase
        {{ 'i',  'b',    0,    0,    9,    0}}, // loadi2_membase
        {{ 'i',  'b',    0,    0,    9,    0}}, // loadu2_membase
        {{ 'i',  'b',    0,    0,    9,    0}}, // loadi4_membase
        {{ 'i',  'b',    0,    0,    9,    0}}, // loadu4_membase
        {{ 'i',  'b',    0,    0, 0x12,    0}}, // loadi8_membase
        {{ 'f',  'b',    0,    0, 0x10,    0}}, // loadr4_membase
        {{ 'f',  'b',    0,    0, 0x10,    0}}, // loadr8_membase
        {{ 'x',  'b',    0,    0,    9,    0}}, // loadx_membase
        {{ 'x',  'b',    0,    0,    7,    0}}, // loadx_aligned_membase
        {{ 'i',    0,    0,    0, 0x10,    0}}, // load_mem
        {{ 'i',    0,    0,    0, 0x10,    0}}, // loadu1_mem
        {{ 'i',    0,    0,    0, 0x10,    0}}, // loadu2_mem
        {{ 'i',    0,    0,    0, 0x10,    0}}, // loadi4_mem
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{ 'i',    0,    0,    0, 0x0a,    0}}, // loadu4_mem
        {{ 'i',    0,    0,    0, 0x10,    0}}, // loadi8_mem
        {{ 'i',  'i',    0,    0,    3,    0}}, // move
        {{ 'f',  'f',    0,    0,    8,    0}}, // fmove
        {{ 'f',  'f',    0,    0,    8,    0}}, // rmove
        {{ 'i',  'f',    0,    0, 0x10,    0}}, // move_f_to_i4
        {{ 'f',  'i',    0,    0, 0x10,    0}}, // move_i4_to_f
        {{ 'i',  'f',    0,    0,    5,    0}}, // move_f_to_i8
        {{ 'f',  'i',    0,    0,    5,    0}}, // move_i8_to_f
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // add_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // sub_imm
        {{ 'i',  'i',    0,    0, 0x0c,    0}}, // mul_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // and_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // or_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // xor_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // shl_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // shr_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // shr_un_imm
        {{   0,    0,    0,    0,    6,    0}}, // br
        {{   0,    0,    0,    0, 0xff,  'c'}}, // tailcall
        {{   0,    0,    0,    0, 0x0e,    0}}, // tailcall_parameter
        {{   0,  'b',    0,    0, 0xff,  'c'}}, // tailcall_reg
        {{   0,  'b',    0,    0, 0xff,  'c'}}, // tailcall_membase
        {{   0,    0,    0,    0,    2,    0}}, // break
        {{ 'c',    0,    0,    0,    8,    0}}, // ceq
        {{ 'c',    0,    0,    0,    8,    0}}, // cgt
        {{ 'c',    0,    0,    0,    8,    0}}, // cgt_un
        {{ 'c',    0,    0,    0,    8,    0}}, // clt
        {{ 'c',    0,    0,    0,    8,    0}}, // clt_un
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_eq
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ge
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_gt
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_le
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_lt
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ne_un
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ge_un
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_gt_un
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_le_un
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_lt_un
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ov
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_no
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_c
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_nc
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ieq
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ige
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_igt
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ile
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ilt
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ine_un
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ige_un
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_igt_un
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ile_un
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ilt_un
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_iov
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ino
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_ic
        {{   0,    0,    0,    0,    8,    0}}, // cond_exc_inc
        {{ 'i',  'i',  'i',    0,    3,  '1'}}, // long_add
        {{ 'i',  'i',  'i',    0,    3,  '1'}}, // long_sub
        {{ 'i',  'i',  'i',    0,    4,  '1'}}, // long_mul
        {{ 'a',  'a',  'i',    0, 0x10,  'd'}}, // long_div
        {{ 'a',  'a',  'i',    0, 0x10,  'd'}}, // long_div_un
        {{ 'd',  'a',  'i',    0, 0x10,  'a'}}, // long_rem
        {{ 'd',  'a',  'i',    0, 0x10,  'a'}}, // long_rem_un
        {{ 'i',  'i',  'i',    0,    3,  '1'}}, // long_and
        {{ 'i',  'i',  'i',    0,    3,  '1'}}, // long_or
        {{ 'i',  'i',  'i',    0,    3,  '1'}}, // long_xor
        {{ 'i',  'i',  's',    0,    3,  '1'}}, // long_shl
        {{ 'i',  'i',  's',    0,    3,  '1'}}, // long_shr
        {{ 'i',  'i',  's',    0,    3,  '1'}}, // long_shr_un
        {{ 'i',  'i',    0,    0,    3,  '1'}}, // long_neg
        {{ 'i',  'i',    0,    0,    3,  '1'}}, // long_not
        {{ 'i',  'i',    0,    0,    4,    0}}, // long_conv_to_i1
        {{ 'i',  'i',    0,    0,    4,    0}}, // long_conv_to_i2
        {{ 'i',  'i',    0,    0,    3,    0}}, // long_conv_to_i4
        {{ 'i',  'i',    0,    0,    3,    0}}, // long_conv_to_i8
        {{ 'f',  'i',    0,    0, 0x0f,    0}}, // long_conv_to_r4
        {{ 'f',  'i',    0,    0,    9,    0}}, // long_conv_to_r8
        {{ 'i',  'i',    0,    0,    3,    0}}, // long_conv_to_u4
        {{ 'i',  'i',    0,    0,    3,    0}}, // long_conv_to_u8
        {{ 'i',  'i',    0,    0,    4,    0}}, // long_conv_to_u2
        {{ 'i',  'i',    0,    0,    4,    0}}, // long_conv_to_u1
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // long_mul_ovf
        {{ 'i',  'i',  'i',    0, 0x16,    0}}, // long_mul_ovf_un
        {{ 'i',  'i',    0,    0, 0x10,    0}}, // long_conv_to_ovf_i4_un
        {{ 'i',  'i',    0,    0, 0x0f,    0}}, // long_conv_to_ovf_u4
        {{ 'c',    0,    0,    0, 0x40,    0}}, // long_ceq
        {{ 'c',    0,    0,    0, 0x40,    0}}, // long_cgt
        {{ 'c',    0,    0,    0, 0x40,    0}}, // long_cgt_un
        {{ 'c',    0,    0,    0, 0x40,    0}}, // long_clt
        {{ 'c',    0,    0,    0, 0x40,    0}}, // long_clt_un
        {{ 'f',  'i',    0,    0, 0x40,    0}}, // long_conv_to_r_un
        {{ 'i',  'i',    0,    0, 0x0c,  '1'}}, // long_add_imm
        {{ 'i',  'i',    0,    0, 0x0c,  '1'}}, // long_sub_imm
        {{ 'i',  'i',    0,    0, 0x10,  '1'}}, // long_mul_imm
        {{ 'i',  'i',    0,    0, 0x0c,  '1'}}, // long_and_imm
        {{ 'i',  'i',    0,    0, 0x0c,  '1'}}, // long_or_imm
        {{ 'i',  'i',    0,    0, 0x0c,  '1'}}, // long_xor_imm
        {{ 'i',  'i',    0,    0, 0x0b,  '1'}}, // long_shl_imm
        {{ 'i',  'i',    0,    0, 0x0b,  '1'}}, // long_shr_imm
        {{ 'i',  'i',    0,    0, 0x0b,  '1'}}, // long_shr_un_imm
        {{   0,    0,    0,    0,    8,    0}}, // long_beq
        {{   0,    0,    0,    0,    8,    0}}, // long_bge
        {{   0,    0,    0,    0,    8,    0}}, // long_bgt
        {{   0,    0,    0,    0,    8,    0}}, // long_ble
        {{   0,    0,    0,    0,    8,    0}}, // long_blt
        {{   0,    0,    0,    0,    8,    0}}, // long_bne_un
        {{   0,    0,    0,    0,    8,    0}}, // long_bge_un
        {{   0,    0,    0,    0,    8,    0}}, // long_bgt_un
        {{   0,    0,    0,    0,    8,    0}}, // long_ble_un
        {{   0,    0,    0,    0,    8,    0}}, // long_blt_un
        {{ 'i',  'i',  'i',    0,    4,  '1'}}, // int_add
        {{ 'i',  'i',  'i',    0,    4,  '1'}}, // int_sub
        {{ 'i',  'i',  'i',    0,    4,  '1'}}, // int_mul
        {{ 'a',  'a',  'i',    0, 0x20,  'd'}}, // int_div
        {{ 'a',  'a',  'i',    0, 0x20,  'd'}}, // int_div_un
        {{ 'd',  'a',  'i',    0, 0x20,  'a'}}, // int_rem
        {{ 'd',  'a',  'i',    0, 0x20,  'a'}}, // int_rem_un
        {{ 'i',  'i',  'i',    0,    4,  '1'}}, // int_and
        {{ 'i',  'i',  'i',    0,    4,  '1'}}, // int_or
        {{ 'i',  'i',  'i',    0,    4,  '1'}}, // int_xor
        {{ 'i',  'i',  's',    0,    4,  '1'}}, // int_shl
        {{ 'i',  'i',  's',    0,    4,  '1'}}, // int_shr
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{ 'i',  'i',  's',    0,    4,  '1'}}, // int_shr_un
        {{ 'i',  'i',    0,    0,    4,  '1'}}, // int_neg
        {{ 'i',  'i',    0,    0,    4,  '1'}}, // int_not
        {{ 'i',  'i',    0,    0,    4,    0}}, // int_conv_to_i1
        {{ 'i',  'i',    0,    0,    4,    0}}, // int_conv_to_i2
        {{ 'i',  'i',    0,    0,    3,    0}}, // int_conv_to_i4
        {{ 'i',  'i',    0,    0,    3,    0}}, // int_conv_to_i8
        {{ 'f',  'i',    0,    0, 0x0f,    0}}, // int_conv_to_r4
        {{ 'f',  'i',    0,    0,    9,    0}}, // int_conv_to_r8
        {{ 'i',  'i',    0,    0,    3,    0}}, // int_conv_to_u4
        {{ 'i',  'i',    0,    0,    3,    0}}, // int_conv_to_u8
        {{ 'i',  'i',    0,    0,    4,    0}}, // int_conv_to_u
        {{ 'i',  'i',    0,    0,    4,    0}}, // int_conv_to_u2
        {{ 'i',  'i',    0,    0,    4,    0}}, // int_conv_to_u1
        {{ 'i',  'i',    0,    0,    4,    0}}, // int_conv_to_i
        {{ 'i',  'i',  'i',    0, 0x20,  '1'}}, // int_mul_ovf
        {{ 'i',  'i',  'i',    0, 0x20,  '1'}}, // int_mul_ovf_un
        {{ 'i',  'i',  'i',    0,    4,  '1'}}, // int_adc
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // int_adc_imm
        {{ 'i',  'i',  'i',    0,    4,  '1'}}, // int_sbb
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // int_sbb_imm
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // int_addcc
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // int_subcc
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // int_add_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // int_sub_imm
        {{ 'i',  'i',    0,    0, 0x20,  '1'}}, // int_mul_imm
        {{ 'a',  'i',    0,    0, 0x20,  'd'}}, // int_div_imm
        {{ 'a',  'i',    0,    0, 0x20,  'd'}}, // int_div_un_imm
        {{ 'd',  'i',    0,    0, 0x20,  'a'}}, // int_rem_un_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // int_and_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // int_or_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // int_xor_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // int_shl_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // int_shr_imm
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // int_shr_un_imm
        {{ 'c',    0,    0,    0,    8,    0}}, // int_ceq
        {{ 'c',    0,    0,    0,    8,    0}}, // int_cgt
        {{ 'c',    0,    0,    0,    8,    0}}, // int_cgt_un
        {{ 'c',    0,    0,    0,    8,    0}}, // int_clt
        {{ 'c',    0,    0,    0,    8,    0}}, // int_clt_un
        {{ 'c',    0,    0,    0,    8,    0}}, // int_cneq
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{ 'c',    0,    0,    0,    8,    0}}, // int_cge
        {{ 'c',    0,    0,    0,    8,    0}}, // int_cle
        {{ 'c',    0,    0,    0,    8,    0}}, // int_cge_un
        {{ 'c',    0,    0,    0,    8,    0}}, // int_cle_un
        {{   0,    0,    0,    0,    8,    0}}, // int_beq
        {{   0,    0,    0,    0,    8,    0}}, // int_bge
        {{   0,    0,    0,    0,    8,    0}}, // int_bgt
        {{   0,    0,    0,    0,    8,    0}}, // int_ble
        {{   0,    0,    0,    0,    8,    0}}, // int_blt
        {{   0,    0,    0,    0,    8,    0}}, // int_bne_un
        {{   0,    0,    0,    0,    8,    0}}, // int_bge_un
        {{   0,    0,    0,    0,    8,    0}}, // int_bgt_un
        {{   0,    0,    0,    0,    8,    0}}, // int_ble_un
        {{   0,    0,    0,    0,    8,    0}}, // int_blt_un
        {{   0,    0,    0,    0, 0x0d,    0}}, // float_beq
        {{   0,    0,    0,    0, 0x20,    0}}, // float_bge
        {{   0,    0,    0,    0, 0x0d,    0}}, // float_bgt
        {{   0,    0,    0,    0, 0x20,    0}}, // float_ble
        {{   0,    0,    0,    0, 0x0d,    0}}, // float_blt
        {{   0,    0,    0,    0, 0x12,    0}}, // float_bne_un
        {{   0,    0,    0,    0, 0x0d,    0}}, // float_bge_un
        {{   0,    0,    0,    0, 0x1e,    0}}, // float_bgt_un
        {{   0,    0,    0,    0, 0x0d,    0}}, // float_ble_un
        {{   0,    0,    0,    0, 0x1e,    0}}, // float_blt_un
        {{ 'f',  'f',  'f',    0,    5,  '1'}}, // float_add
        {{ 'f',  'f',  'f',    0,    5,  '1'}}, // float_sub
        {{ 'f',  'f',  'f',    0,    5,  '1'}}, // float_mul
        {{ 'f',  'f',  'f',    0,    5,  '1'}}, // float_div
        {{ 'f',  'f',  'f',    0,    5,  '1'}}, // float_div_un
        {{ 'f',  'f',  'f',    0, 0x13,  '1'}}, // float_rem
        {{ 'f',  'f',  'f',    0, 0x13,  '1'}}, // float_rem_un
        {{ 'f',  'f',  'f',    0,    5,  '1'}}, // r4_add
        {{ 'f',  'f',  'f',    0,    5,  '1'}}, // r4_sub
        {{ 'f',  'f',  'f',    0,    5,  '1'}}, // r4_mul
        {{ 'f',  'f',  'f',    0,    5,  '1'}}, // r4_div
        {{ 'f',  'f',    0,    0, 0x17,  '1'}}, // float_neg
        {{ 'f',  'f',    0,    0,    3,  '1'}}, // float_not
        {{ 'i',  'f',    0,    0,  '1',    0}}, // float_conv_to_i1
        {{ 'i',  'f',    0,    0,  '1',    0}}, // float_conv_to_i2
        {{ 'i',  'f',    0,    0,  '1',    0}}, // float_conv_to_i4
        {{ 'i',  'f',    0,    0,  '1',    0}}, // float_conv_to_i8
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{ 'f',  'f',    0,    0, 0x11,    0}}, // float_conv_to_r4
        {{ 'i',  'f',    0,    0,  '1',    0}}, // float_conv_to_u4
        {{ 'i',  'f',    0,    0,  '1',    0}}, // float_conv_to_u8
        {{ 'f',  'f',    0,    0, 0x17,  '1'}}, // r4_neg
        {{ 'i',  'f',    0,    0, 0x20,    0}}, // r4_conv_to_i1
        {{ 'i',  'f',    0,    0, 0x20,    0}}, // r4_conv_to_i2
        {{ 'i',  'f',    0,    0, 0x10,    0}}, // r4_conv_to_i4
        {{ 'i',  'f',    0,    0, 0x20,    0}}, // r4_conv_to_i8
        {{ 'f',  'f',    0,    0, 0x11,    0}}, // r4_conv_to_r4
        {{ 'f',  'f',    0,    0, 0x11,    0}}, // r4_conv_to_r8
        {{ 'i',  'f',    0,    0, 0x20,    0}}, // r4_conv_to_u4
        {{ 'i',  'f',    0,    0,  '1',    0}}, // float_conv_to_u2
        {{ 'i',  'f',    0,    0,  '1',    0}}, // float_conv_to_u1
        {{ 'i',  'f',    0,    0,  '1',    0}}, // float_conv_to_i
        {{ 'a',  'f',    0,    0, 0x28,    0}}, // float_conv_to_ovf_i
        {{ 'a',  'f',    0,    0, 0x28,    0}}, // float_conv_to_ovd_u
        {{   0,    0,    0,    0,    0,    0}}, // float_mul_ovf
        {{ 'i',  'f',  'f',    0, 0x23,    0}}, // float_ceq
        {{ 'i',  'f',  'f',    0, 0x23,    0}}, // float_cgt
        {{ 'i',  'f',  'f',    0,  '0',    0}}, // float_cgt_un
        {{ 'i',  'f',  'f',    0, 0x23,    0}}, // float_clt
        {{ 'i',  'f',  'f',    0, 0x2a,    0}}, // float_clt_un
        {{ 'i',  'f',  'f',    0, 0x2a,    0}}, // float_cneq
        {{ 'i',  'f',  'f',    0, 0x23,    0}}, // float_cge
        {{ 'i',  'f',  'f',    0, 0x23,    0}}, // float_cle
        {{ 'i',  'f',  'b',    0, 0x23,    0}}, // float_ceq_membase
        {{ 'i',  'f',  'b',    0, 0x23,    0}}, // float_cgt_membase
        {{ 'i',  'f',  'b',    0,  '0',    0}}, // float_cgt_un_membase
        {{ 'i',  'f',  'b',    0, 0x23,    0}}, // float_clt_membase
        {{ 'i',  'f',  'b',    0, 0x2a,    0}}, // float_clt_un_membase
        {{ 'i',  'f',    0,    0, 0x2e,    0}}, // float_conv_to_u
        {{ 'f',  'f',    0,    0, 0x2b,    0}}, // ckfinite
        {{ 'i',  'f',    0,    0, 0x20,    0}}, // r4_conv_to_u2
        {{ 'i',  'f',    0,    0, 0x20,    0}}, // r4_conv_to_u1
        {{ 'i',  'f',    0,    0, 0x20,    0}}, // r4_conv_to_i
        {{ 'i',  'f',  'f',    0, 0x23,    0}}, // r4_ceq
        {{ 'i',  'f',  'f',    0, 0x23,    0}}, // r4_cgt
        {{ 'i',  'f',  'f',    0,  '0',    0}}, // r4_cgt_un
        {{ 'i',  'f',  'f',    0, 0x23,    0}}, // r4_clt
        {{ 'i',  'f',  'f',    0, 0x2a,    0}}, // r4_clt_un
        {{ 'i',  'f',  'f',    0, 0x2a,    0}}, // r4_cneq
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{ 'i',  'f',  'f',    0, 0x23,    0}}, // r4_cge
        {{ 'i',  'f',  'f',    0, 0x23,    0}}, // r4_cle
        {{ 'i',    0,    0,    0, 0x12,    0}}, // jump_table
        {{ 'i',    0,    0,    0, 0x0a,    0}}, // aotconst
        {{   0,    0,    0,    0, 0x0e,  'c'}}, // call_handler
        {{   0,    0,    0,    0, 0x10,    0}}, // start_handler
        {{   0,  'a',    0,    0,    9,    0}}, // endfilter
        {{   0,    0,    0,    0,    9,    0}}, // endfinally
        {{ 'a',    0,    0,    0, 0x10,    0}}, // get_ex_obj
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // int_min_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // int_max_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // long_min_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // long_max_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // int_min
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // int_max
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // long_min
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // long_max
        {{ 'i',  'i',  'i',    0,    3,  '1'}}, // adc
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // adc_imm
        {{ 'i',  'i',  'i',    0,    3,  '1'}}, // sbb
        {{ 'i',  'i',    0,    0,    8,  '1'}}, // sbb_imm
        {{ 'i',  'i',  'i',    0,    3,  '1'}}, // addcc
        {{ 'i',  'i',  'i',    0,    3,  '1'}}, // subcc
        {{   0,  'i',    0,    0,    3,    0}}, // br_reg
        {{ 'i',  'i',    0,    0,    4,    0}}, // sext_i1
        {{ 'i',  'i',    0,    0,    4,    0}}, // sext_i2
        {{ 'i',  'i',    0,    0,    8,    0}}, // sext_i4
        {{ 'i',  'i',    0,    0,    4,    0}}, // zext_i4
        {{ 'i',  'i',  'i',    0,    3,  '1'}}, // laddcc
        {{ 'i',  'i',  'i',    0,    3,  '1'}}, // lsubcc
        {{ 'f',  'f',    0,    0, 0x20,    0}}, // sin
        {{ 'f',  'f',    0,    0, 0x20,    0}}, // cos
        {{ 'f',  'f',    0,    0, 0x20,  '1'}}, // abs
        {{ 'f',  'f',    0,    0, 0x3b,    0}}, // tan
        {{ 'f',  'f',    0,    0,    9,    0}}, // atan
        {{ 'f',  'f',    0,    0, 0x20,    0}}, // sqrt
        {{   0,  'a',  'i',    0,  '8',  'd'}}, // card_table_wbarrier
        {{ 'i',    0,    0,    0, 0x20,    0}}, // tls_get
        {{   0,  'i',    0,    0, 0x10,    0}}, // tls_set
        {{   0,  'i',    0,    0,    0,    0}}, // dummy_use
        {{   0,    0,    0,    0,    0,    0}}, // not_reached
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{   0,  'i',    0,    0,    0,    0}}, // not_null
        {{ 'i',  'x',    0,    0,    5,    0}}, // extract_i4
        {{ 'f',  'i',    0,    0, 0x0a,    0}}, // iconv_to_r4_raw
        {{ 'i',  'x',    0,    0, 0x0d,    0}}, // extract_i2
        {{ 'i',  'x',    0,    0, 0x0d,    0}}, // extract_u2
        {{ 'i',  'x',    0,    0, 0x0d,    0}}, // extract_i1
        {{ 'i',  'x',    0,    0, 0x0d,    0}}, // extract_u1
        {{ 'f',  'x',    0,    0,    5,    0}}, // extract_r8
        {{ 'i',  'x',    0,    0,    9,    0}}, // extract_i8
        {{ 'x',  'x',  'i',    0,    6,  '1'}}, // insert_i2
        {{ 'i',  'x',    0,    0,    6,    0}}, // extractx_u2
        {{ 'x',  'i',  'i',    0, 0x12,  'x'}}, // insertx_u1_slow
        {{ 'x',  'x',  'i',    0, 0x10,  'x'}}, // insertx_i4_slow
        {{ 'x',  'x',  'f',    0, 0x18,    0}}, // insertx_r4_slow
        {{ 'x',  'x',  'f',    0, 0x18,    0}}, // insertx_r8_slow
        {{ 'x',  'x',  'i',    0, 0x0d,    0}}, // insertx_i8_slow
        {{ 'x',  'f',    0,    0,    4,    0}}, // fconv_to_r8_x
        {{ 'y',  'x',    0,    0,    7,    0}}, // xconv_r8_to_i4
        {{ 'x',  'i',    0,    0,    5,    0}}, // iconv_to_x
        {{ 'x',  'i',    0,    0, 0x12,    0}}, // expand_i2
        {{ 'x',  'i',    0,    0, 0x0b,    0}}, // expand_i4
        {{ 'x',  'f',    0,    0, 0x10,    0}}, // expand_r4
        {{ 'x',  'i',    0,    0, 0x0b,    0}}, // expand_i8
        {{ 'x',  'f',    0,    0, 0x0d,    0}}, // expand_r8
        {{ 'x',  'x',  'x',    0,    4,  '1'}}, // addps
        {{ 'x',  'x',  'x',    0,    4,  '1'}}, // divps
        {{ 'x',  'x',  'x',    0,    4,  '1'}}, // mulps
        {{ 'x',  'x',  'x',    0,    4,  '1'}}, // subps
        {{ 'x',  'x',  'x',    0,    4,  '1'}}, // maxps
        {{ 'x',  'x',  'x',    0,    4,  '1'}}, // minps
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // compps
        {{ 'x',  'x',  'x',    0,    4,  '1'}}, // andps
        {{ 'x',  'x',  'x',    0,    4,  '1'}}, // andnps
        {{ 'x',  'x',  'x',    0,    4,  '1'}}, // orps
        {{ 'x',  'x',  'x',    0,    4,  '1'}}, // xorps
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // haddps
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // hsubps
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // addsubps
        {{ 'x',  'x',    0,    0,    5,    0}}, // dupps_low
        {{ 'x',  'x',    0,    0,    5,    0}}, // dupps_high
        {{ 'x',  'x',    0,    0,    5,    0}}, // rsqrtps
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{ 'x',  'x',    0,    0,    5,    0}}, // sqrtps
        {{ 'x',  'x',    0,    0,    5,    0}}, // rcpps
        {{ 'x',  'x',    0,    0,    6,    0}}, // pshuflew_high
        {{ 'x',  'x',    0,    0,    6,    0}}, // pshuflew_low
        {{ 'x',  'x',    0,    0,    6,    0}}, // pshufled
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // shufps
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // shufpd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // addpd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // divpd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // mulpd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // subpd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // maxpd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // minpd
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // comppd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // andpd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // andnpd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // orpd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // xorpd
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // haddpd
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // hsubpd
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // addsubpd
        {{ 'x',  'x',    0,    0,    6,    0}}, // duppd
        {{ 'x',  'x',    0,    0,    5,  '1'}}, // sqrtpd
        {{ 'i',  'x',    0,    0,    6,    0}}, // extract_mask
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pand
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pandn
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // por
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pxor
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // paddb
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // paddw
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // paddd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // paddq
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // psubb
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // psubw
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // psubd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // psubq
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pmaxb_un
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // pmaxw_un
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // pmaxd_un
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // pmaxb
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pmaxw
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // pmaxd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pavgb_un
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pavgw_un
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pminb_un
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // pminw_un
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // pmind_un
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // pminb
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pminw
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // pmind
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pcmpeqb
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pcmpeqw
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pcmpeqd
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // pcmpeqq
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pcmpgtb
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pcmpgtw
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pcmpgtd
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // pcmpgtq
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // psum_abs_diff
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_lowb
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_loww
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_lowd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_lowq
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_lowps
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_lowpd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_highb
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_highw
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_highd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_highq
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_highps
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // unpack_highpd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // packw
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // packd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // packw_un
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // packd_un
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // paddb_sat
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // paddb_sat_un
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // paddw_sat
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // paddw_sat_un
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // psubb_sat
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // psubb_sat_un
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // psubw_sat
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // psubw_sat_un
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pmulw
        {{ 'x',  'x',  'x',    0,    6,  '1'}}, // pmuld
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pmulq
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pmulw_high_un
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pmulw_high
        {{ 'x',  'x',    0,    0,    6,  '1'}}, // pshrw
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pshrw_reg
        {{ 'x',  'x',    0,    0,    6,  '1'}}, // psarw
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // psarw_reg
        {{ 'x',  'x',    0,    0,    6,  '1'}}, // pshlw
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pshlw_reg
        {{ 'x',  'x',    0,    0,    6,  '1'}}, // pshrd
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pshrd_reg
        {{ 'x',  'x',    0,    0,    6,  '1'}}, // pshrq
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pshrq_reg
        {{ 'x',  'x',    0,    0,    6,  '1'}}, // psard
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // psard_reg
        {{ 'x',  'x',    0,    0,    6,  '1'}}, // pshld
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pshld_reg
        {{ 'x',  'x',    0,    0,    6,  '1'}}, // pshlq
        {{ 'x',  'x',  'x',    0,    5,  '1'}}, // pshlq_reg
        {{   0,  'b',    0,    0,    4,    0}}, // prefetch_membase
        {{ 'x',  'x',    0,    0,    5,  '1'}}, // cvtdq2pd
        {{ 'x',  'x',    0,    0,    4,  '1'}}, // cvtdq2ps
        {{ 'x',  'x',    0,    0,    5,  '1'}}, // cvtpd2dq
        {{ 'x',  'x',    0,    0,    5,  '1'}}, // cvtpd2ps
        {{ 'x',  'x',    0,    0,    5,  '1'}}, // cvtps2dq
        {{ 'x',  'x',    0,    0,    4,  '1'}}, // cvtps2pd
        {{ 'x',  'x',    0,    0,    5,  '1'}}, // cvttpd2dq
        {{ 'x',  'x',    0,    0,    5,  '1'}}, // cvttps2dq
        {{ 'x',  'x',    0,    0, 0x0a,    0}}, // roundp
        {{ 'x',  'x',    0,    0,    5,    0}}, // xmove
        {{ 'x',    0,    0,    0,    5,    0}}, // xzero
        {{ 'x',    0,    0,    0,    5,    0}}, // xones
        {{   0,    0,    0,    0,    3,    0}}, // memory_barrier
        {{ 'c',  'b',    0,    0,    9,    0}}, // atomic_load_i1
        {{ 'i',  'b',    0,    0,    9,    0}}, // atomic_load_i2
        {{ 'i',  'b',    0,    0,    9,    0}}, // atomic_load_i4
        {{ 'i',  'b',    0,    0,    9,    0}}, // atomic_load_i8
        {{ 'c',  'b',    0,    0,    9,    0}}, // atomic_load_u1
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{ 'i',  'b',    0,    0,    9,    0}}, // atomic_load_u2
        {{ 'i',  'b',    0,    0,    9,    0}}, // atomic_load_u4
        {{ 'i',  'b',    0,    0,    9,    0}}, // atomic_load_u8
        {{ 'f',  'b',    0,    0, 0x10,    0}}, // atomic_load_r4
        {{ 'f',  'b',    0,    0, 0x10,    0}}, // atomic_load_r8
        {{ 'b',  'c',    0,    0, 0x0c,    0}}, // atomic_store_i1
        {{ 'b',  'i',    0,    0, 0x0c,    0}}, // atomic_store_i2
        {{ 'b',  'i',    0,    0, 0x0c,    0}}, // atomic_store_i4
        {{ 'b',  'i',    0,    0, 0x0c,    0}}, // atomic_store_i8
        {{ 'b',  'c',    0,    0, 0x0c,    0}}, // atomic_store_u1
        {{ 'b',  'i',    0,    0, 0x0c,    0}}, // atomic_store_u2
        {{ 'b',  'i',    0,    0, 0x0c,    0}}, // atomic_store_u4
        {{ 'b',  'i',    0,    0, 0x0c,    0}}, // atomic_store_u8
        {{ 'b',  'f',    0,    0, 0x12,    0}}, // atomic_store_r4
        {{ 'b',  'f',    0,    0, 0x0d,    0}}, // atomic_store_r8
        {{ 'i',  'b',  'i',    0, 0x20,    0}}, // atomic_add_i4
        {{ 'i',  'b',  'i',    0, 0x20,    0}}, // atomic_add_i8
        {{ 'i',  'b',  'i',    0, 0x0c,    0}}, // atomic_exchange_i4
        {{ 'i',  'b',  'i',    0, 0x0c,    0}}, // atomic_exchange_i8
        {{ 'a',  'b',  'i',  'a', 0x18,    0}}, // atomic_cas_i4
        {{ 'a',  'b',  'i',  'a', 0x18,    0}}, // atomic_cas_i8
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_ieq
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_ige
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_igt
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_ile
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_ilt
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_ine_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_ige_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_igt_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_ile_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_ilt_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_leq
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_lge
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_lgt
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_lle
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_llt
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_lne_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_lge_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_lgt_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_lle_un
        {{ 'i',  'i',  'i',    0, 0x10,  '1'}}, // cmov_llt_un
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{   0,    0,    0,    0,    0,    0}}, // liverange_start
        {{   0,    0,    0,    0,    0,    0}}, // liverange_end
        {{   0,    0,    0,    0,    0,    0}}, // gc_liveness_def
        {{   0,    0,    0,    0,    0,    0}}, // gc_liveness_use
        {{   0,    0,    0,    0,    0,    0}}, // gc_spill_slot_liveness_def
        {{   0,    0,    0,    0,    0,    0}}, // gc_param_slot_liveness_def
        {{   0,  'i',    0,    0, 0x28,  'c'}}, // gc_safe_point
        {{   0,  'A',    0,    0, 0x20,  'c'}}, // generic_class_init
        {{   0,  'i',    0,    0,    5,    0}}, // x86_test_null
        {{   0,  'b',  'i',    0,    9,    0}}, // x86_compare_membase_reg
        {{   0,  'b',    0,    0, 0x0d,    0}}, // x86_compare_membase_imm
        {{   0,  'b',    0,    0,    9,    0}}, // x86_compare_membase8_imm
        {{   0,  'i',  'b',    0,    8,    0}}, // x86_compare_reg_membase
        {{ 'i',  'i',    0,    0,    3,  '1'}}, // x86_inc_reg
        {{   0,  'b',    0,    0,    8,    0}}, // x86_inc_membase
        {{ 'i',  'i',    0,    0,    3,  '1'}}, // x86_dec_reg
        {{   0,  'b',    0,    0,    8,    0}}, // x86_dec_membase
        {{   0,  'b',    0,    0, 0x0d,    0}}, // x86_add_membase_imm
        {{   0,  'b',    0,    0, 0x0d,    0}}, // x86_sub_membase_imm
        {{   0,  'b',    0,    0, 0x0c,    0}}, // x86_and_membase_imm
        {{   0,  'b',    0,    0, 0x0c,    0}}, // x86_or_membase_imm
        {{   0,  'b',    0,    0, 0x0c,    0}}, // x86_xor_membase_imm
        {{   0,  'b',  'i',    0, 0x0c,    0}}, // x86_add_membase_reg
        {{   0,  'b',  'i',    0, 0x0c,    0}}, // x86_sub_membase_reg
        {{   0,  'b',  'i',    0, 0x0c,    0}}, // x86_and_membase_reg
        {{   0,  'b',  'i',    0, 0x0c,    0}}, // x86_or_membase_reg
        {{   0,  'b',  'i',    0, 0x0c,    0}}, // x86_xor_membase_reg
        {{   0,  'b',  'i',    0, 0x0e,    0}}, // x86_mul_membase_reg
        {{ 'i',  'i',  'b',    0, 0x0d,  '1'}}, // x86_add_reg_membase
        {{ 'i',  'i',  'b',    0, 0x0d,  '1'}}, // x86_sub_reg_membase
        {{ 'i',  'i',  'b',    0, 0x0d,  '1'}}, // x86_mul_reg_membase
        {{ 'i',  'i',  'b',    0, 0x0d,  '1'}}, // x86_and_reg_membase
        {{ 'i',  'i',  'b',    0, 0x0d,  '1'}}, // x86_or_reg_membase
        {{ 'i',  'i',  'b',    0, 0x0d,  '1'}}, // x86_xor_reg_membase
        {{   0,  'b',    0,    0,    8,    0}}, // x86_push_membase
        {{   0,    0,    0,    0,    6,    0}}, // x86_push_imm
        {{   0,  'i',    0,    0,    3,    0}}, // x86_push
        {{   0,  'b',    0,    0, 0x28,    0}}, // x86_push_obj
        {{ 'i',  'i',  'i',    0,    8,    0}}, // x86_lea
        {{ 'i',  'i',    0,    0, 0x0b,    0}}, // x86_lea_membase
        {{   0,  'i',  'i',    0,    2,  'x'}}, // x86_xchg
//  dest  src1  src2  src3   len  clob
// ----- ----- ----- ----  ----- -----
        {{   0,  'f',    0,    0,    3,    0}}, // x86_fpop
        {{   0,  'b',    0,    0,    9,    0}}, // x86_seteq_membase
        {{   0,  'i',    0,    0,    5,    0}}, // amd64_test_null
        {{ 'f',  'f',    0,    0, 0x0e,  'm'}}, // amd64_set_xmmreg_r4
        {{ 'f',  'f',    0,    0, 0x0e,  'm'}}, // amd64_set_xmmreg_r8
        {{   0,  'b',  'i',    0,    8,    0}}, // amd64_icompare_membase_reg
        {{   0,  'b',    0,    0, 0x0d,    0}}, // amd64_icompare_membase_imm
        {{   0,  'i',  'b',    0,    8,    0}}, // amd64_icompare_reg_membase
        {{   0,  'b',  'i',    0,    9,    0}}, // amd64_compare_membase_reg
        {{   0,  'b',    0,    0, 0x0e,    0}}, // amd64_compare_membase_imm
        {{   0,  'i',  'b',    0,    9,    0}}, // amd64_compare_reg_membase
        {{   0,  'b',  'i',    0, 0x0d,    0}}, // amd64_add_membase_reg
        {{   0,  'b',  'i',    0, 0x0d,    0}}, // amd64_sub_membase_reg
        {{   0,  'b',  'i',    0, 0x0d,    0}}, // amd64_and_membase_reg
        {{   0,  'b',  'i',    0, 0x0d,    0}}, // amd64_or_membase_reg
        {{   0,  'b',  'i',    0, 0x0d,    0}}, // amd64_xor_membase_reg
        {{   0,  'b',  'i',    0, 0x0f,    0}}, // amd64_mul_membase_reg
        {{   0,  'b',    0,    0, 0x10,    0}}, // amd64_add_membase_imm
        {{   0,  'b',    0,    0, 0x10,    0}}, // amd64_sub_membase_imm
        {{   0,  'b',    0,    0, 0x0d,    0}}, // amd64_and_membase_imm
        {{   0,  'b',    0,    0, 0x0d,    0}}, // amd64_or_membase_imm
        {{   0,  'b',    0,    0, 0x0d,    0}}, // amd64_xor_membase_imm
        {{ 'i',  'i',    0,    0, 0x0b,    0}}, // amd64_lea_membase
        {{ 'i',  'i',  'b',    0, 0x0e,  '1'}}, // amd64_add_reg_membase
        {{ 'i',  'i',  'b',    0, 0x0e,  '1'}}, // amd64_sub_reg_membase
        {{ 'i',  'i',  'b',    0, 0x0e,  '1'}}, // amd64_and_reg_membase
        {{ 'i',  'i',  'b',    0, 0x0e,  '1'}}, // amd64_or_reg_membase
        {{ 'i',  'i',  'b',    0, 0x0e,  '1'}}, // amd64_xor_reg_membase
        {{ 'i',  'i',  'i',    0, 0x0a,    0}}, // amd64_loadi8_memindex
        {{   0,    0,    0,    0, 0x10,    0}}, // amd64_save_sp_to_lmf
        {{ 'i',    0,    0,    0, 0x20,    0}}, // get_last_error
        {{   0,  'i',    0,    0, 0x80,    0}}, // fill_prof_call_ctx
        {{ 'i',  'i',    0,    0, 0x10,    0}}, // lzcnt32
        {{ 'i',  'i',    0,    0, 0x10,    0}}, // lzcnt64
        {{ 'i',  'i',    0,    0, 0x10,    0}}, // popcnt32
        {{ 'i',  'i',    0,    0, 0x10,    0}}, // popcnt64
};
const guint16 mono_amd64_desc_idx [] = {
        0,  // load
        0,  // ldaddr
        0,  // store
        1, // nop
        2, // hard_nop
        3, // relaxed_nop
        0,  // phi
        0,  // fphi
        0,  // vphi
        4, // compare
        5, // compare_imm
        6, // fcompare
        7, // rcompare
        8, // lcompare
        9, // icompare
        10, // icompare_imm
        11, // lcompare_imm
        0,  // local
        0,  // arg
        0,  // gsharedvt_local
        0,  // gsharedvt_arg_regoffset
        0,  // outarg_vt
        0,  // outarg_vtretaddr
        0,  // setret
        0,  // setfret
        0,  // setlret
        12, // localloc
        13, // localloc_imm
        14, // check_this
        15, // seq_point
        16, // il_seq_point
        0,  // implicit_exception
        0,  // box
        0,  // box_iconst
        0,  // typed_objref
        17, // voidcall
        18, // voidcall_reg
        19, // voidcall_membase
        20, // call
        21, // call_reg
        22, // call_membase
        23, // fcall
        24, // fcall_reg
        25, // fcall_membase
        26, // rcall
        27, // rcall_reg
        28, // rcall_membase
        29, // lcall
        30, // lcall_reg
        31, // lcall_membase
        32, // vcall
        33, // vcall_reg
        34, // vcall_membase
        35, // vcall2
        36, // vcall2_reg
        37, // vcall2_membase
        38, // dyn_call
        39, // iconst
        40, // i8const
        41, // r4const
        42, // r8const
        43, // dummy_iconst
        44, // dummy_i8const
        45, // dummy_r8const
        46, // dummy_r4const
        0,  // dummy_vzero
        0,  // regvar
        0,  // regoffset
        0,  // vtarg_addr
        47, // label
        0,  // switch
        48, // throw
        49, // rethrow
        50, // arglist
        51, // store_membase_reg
        52, // storei1_membase_reg
        53, // storei2_membase_reg
        54, // storei4_membase_reg
        55, // storei8_membase_reg
        56, // storer4_membase_reg
        57, // storer8_membase_reg
        58, // storex_membase_reg
        59, // storex_aligned_membase_reg
        60, // storex_nta_membase_reg
        61, // store_membase_imm
        62, // storei1_membase_imm
        63, // storei2_membase_imm
        64, // storei4_membase_imm
        65, // storei8_membase_imm
        66, // storex_membase
        0,  // storev_membase
        67, // load_membase
        68, // loadi1_membase
        69, // loadu1_membase
        70, // loadi2_membase
        71, // loadu2_membase
        72, // loadi4_membase
        73, // loadu4_membase
        74, // loadi8_membase
        75, // loadr4_membase
        76, // loadr8_membase
        77, // loadx_membase
        78, // loadx_aligned_membase
        0,  // loadv_membase
        0,  // load_memindex
        0,  // loadi1_memindex
        0,  // loadu1_memindex
        0,  // loadi2_memindex
        0,  // loadu2_memindex
        0,  // loadi4_memindex
        0,  // loadu4_memindex
        0,  // loadi8_memindex
        0,  // loadr4_memindex
        0,  // loadr8_memindex
        0,  // store_memindex
        0,  // storei1_memindex
        0,  // storei2_memindex
        0,  // storei4_memindex
        0,  // storei8_memindex
        0,  // storer4_memindex
        0,  // storer8_memindex
        79, // load_mem
        80, // loadu1_mem
        81, // loadu2_mem
        82, // loadi4_mem
        83, // loadu4_mem
        84, // loadi8_mem
        85, // move
        0,  // lmove
        86, // fmove
        0,  // vmove
        87, // rmove
        88, // move_f_to_i4
        89, // move_i4_to_f
        90, // move_f_to_i8
        91, // move_i8_to_f
        0,  // vzero
        92, // add_imm
        93, // sub_imm
        94, // mul_imm
        0,  // div_imm
        0,  // div_un_imm
        0,  // rem_imm
        0,  // rem_un_imm
        95, // and_imm
        96, // or_imm
        97, // xor_imm
        98, // shl_imm
        99, // shr_imm
        100, // shr_un_imm
        101, // br
        102, // tailcall
        103, // tailcall_parameter
        104, // tailcall_reg
        105, // tailcall_membase
        106, // break
        107, // ceq
        108, // cgt
        109, // cgt_un
        110, // clt
        111, // clt_un
        112, // cond_exc_eq
        113, // cond_exc_ge
        114, // cond_exc_gt
        115, // cond_exc_le
        116, // cond_exc_lt
        117, // cond_exc_ne_un
        118, // cond_exc_ge_un
        119, // cond_exc_gt_un
        120, // cond_exc_le_un
        121, // cond_exc_lt_un
        122, // cond_exc_ov
        123, // cond_exc_no
        124, // cond_exc_c
        125, // cond_exc_nc
        126, // cond_exc_ieq
        127, // cond_exc_ige
        128, // cond_exc_igt
        129, // cond_exc_ile
        130, // cond_exc_ilt
        131, // cond_exc_ine_un
        132, // cond_exc_ige_un
        133, // cond_exc_igt_un
        134, // cond_exc_ile_un
        135, // cond_exc_ilt_un
        136, // cond_exc_iov
        137, // cond_exc_ino
        138, // cond_exc_ic
        139, // cond_exc_inc
        140, // long_add
        141, // long_sub
        142, // long_mul
        143, // long_div
        144, // long_div_un
        145, // long_rem
        146, // long_rem_un
        147, // long_and
        148, // long_or
        149, // long_xor
        150, // long_shl
        151, // long_shr
        152, // long_shr_un
        153, // long_neg
        154, // long_not
        155, // long_conv_to_i1
        156, // long_conv_to_i2
        157, // long_conv_to_i4
        158, // long_conv_to_i8
        159, // long_conv_to_r4
        160, // long_conv_to_r8
        161, // long_conv_to_u4
        162, // long_conv_to_u8
        163, // long_conv_to_u2
        164, // long_conv_to_u1
        0,  // long_conv_to_i
        0,  // long_conv_to_ovf_i
        0,  // long_conv_to_ovf_u
        0,  // long_add_ovf
        0,  // long_add_ovf_un
        165, // long_mul_ovf
        166, // long_mul_ovf_un
        0,  // long_sub_ovf
        0,  // long_sub_ovf_un
        0,  // long_conv_to_ovf_i1_un
        0,  // long_conv_to_ovf_i2_un
        167, // long_conv_to_ovf_i4_un
        0,  // long_conv_to_ovf_i8_un
        0,  // long_conv_to_ovf_u1_un
        0,  // long_conv_to_ovf_u2_un
        0,  // long_conv_to_ovf_u4_un
        0,  // long_conv_to_ovf_u8_un
        0,  // long_conv_to_ovf_i_un
        0,  // long_conv_to_ovf_u_un
        0,  // long_conv_to_ovf_i1
        0,  // long_conv_to_ovf_u1
        0,  // long_conv_to_ovf_i2
        0,  // long_conv_to_ovf_u2
        0,  // long_conv_to_ovf_i4
        168, // long_conv_to_ovf_u4
        0,  // long_conv_to_ovf_i8
        0,  // long_conv_to_ovf_u8
        169, // long_ceq
        170, // long_cgt
        171, // long_cgt_un
        172, // long_clt
        173, // long_clt_un
        174, // long_conv_to_r_un
        0,  // long_conv_to_u
        175, // long_add_imm
        176, // long_sub_imm
        177, // long_mul_imm
        178, // long_and_imm
        179, // long_or_imm
        180, // long_xor_imm
        181, // long_shl_imm
        182, // long_shr_imm
        183, // long_shr_un_imm
        0,  // long_div_imm
        0,  // long_div_un_imm
        0,  // long_rem_imm
        0,  // long_rem_un_imm
        184, // long_beq
        185, // long_bge
        186, // long_bgt
        187, // long_ble
        188, // long_blt
        189, // long_bne_un
        190, // long_bge_un
        191, // long_bgt_un
        192, // long_ble_un
        193, // long_blt_un
        0,  // long_conv_to_r8_2
        0,  // long_conv_to_r4_2
        0,  // long_conv_to_r_un_2
        0,  // long_conv_to_ovf_i4_2
        194, // int_add
        195, // int_sub
        196, // int_mul
        197, // int_div
        198, // int_div_un
        199, // int_rem
        200, // int_rem_un
        201, // int_and
        202, // int_or
        203, // int_xor
        204, // int_shl
        205, // int_shr
        206, // int_shr_un
        207, // int_neg
        208, // int_not
        209, // int_conv_to_i1
        210, // int_conv_to_i2
        211, // int_conv_to_i4
        212, // int_conv_to_i8
        213, // int_conv_to_r4
        214, // int_conv_to_r8
        215, // int_conv_to_u4
        216, // int_conv_to_u8
        0,  // int_conv_to_r_un
        217, // int_conv_to_u
        218, // int_conv_to_u2
        219, // int_conv_to_u1
        220, // int_conv_to_i
        0,  // int_conv_to_ovf_i
        0,  // int_conv_to_ovf_u
        0,  // int_add_ovf
        0,  // int_add_ovf_un
        221, // int_mul_ovf
        222, // int_mul_ovf_un
        0,  // int_sub_ovf
        0,  // int_sub_ovf_un
        0,  // int_conv_to_ovf_i1_un
        0,  // int_conv_to_ovf_i2_un
        0,  // int_conv_to_ovf_i4_un
        0,  // int_conv_to_ovf_i8_un
        0,  // int_conv_to_ovf_u1_un
        0,  // int_conv_to_ovf_u2_un
        0,  // int_conv_to_ovf_u4_un
        0,  // int_conv_to_ovf_u8_un
        0,  // int_conv_to_ovf_i_un
        0,  // int_conv_to_ovf_u_un
        0,  // int_conv_to_ovf_i1
        0,  // int_conv_to_ovf_u1
        0,  // int_conv_to_ovf_i2
        0,  // int_conv_to_ovf_u2
        0,  // int_conv_to_ovf_i4
        0,  // int_conv_to_ovf_u4
        0,  // int_conv_to_ovf_i8
        0,  // int_conv_to_ovf_u8
        223, // int_adc
        224, // int_adc_imm
        225, // int_sbb
        226, // int_sbb_imm
        227, // int_addcc
        228, // int_subcc
        229, // int_add_imm
        230, // int_sub_imm
        231, // int_mul_imm
        232, // int_div_imm
        233, // int_div_un_imm
        0,  // int_rem_imm
        234, // int_rem_un_imm
        235, // int_and_imm
        236, // int_or_imm
        237, // int_xor_imm
        238, // int_shl_imm
        239, // int_shr_imm
        240, // int_shr_un_imm
        241, // int_ceq
        242, // int_cgt
        243, // int_cgt_un
        244, // int_clt
        245, // int_clt_un
        246, // int_cneq
        247, // int_cge
        248, // int_cle
        249, // int_cge_un
        250, // int_cle_un
        251, // int_beq
        252, // int_bge
        253, // int_bgt
        254, // int_ble
        255, // int_blt
        256, // int_bne_un
        257, // int_bge_un
        258, // int_bgt_un
        259, // int_ble_un
        260, // int_blt_un
        261, // float_beq
        262, // float_bge
        263, // float_bgt
        264, // float_ble
        265, // float_blt
        266, // float_bne_un
        267, // float_bge_un
        268, // float_bgt_un
        269, // float_ble_un
        270, // float_blt_un
        0,  // r4_beq
        0,  // r4_bge
        0,  // r4_bgt
        0,  // r4_ble
        0,  // r4_blt
        0,  // r4_bne_un
        0,  // r4_bge_un
        0,  // r4_bgt_un
        0,  // r4_ble_un
        0,  // r4_blt_un
        271, // float_add
        272, // float_sub
        273, // float_mul
        274, // float_div
        275, // float_div_un
        276, // float_rem
        277, // float_rem_un
        278, // r4_add
        279, // r4_sub
        280, // r4_mul
        281, // r4_div
        0,  // r4_div_un
        0,  // r4_rem
        0,  // r4_rem_un
        282, // float_neg
        283, // float_not
        284, // float_conv_to_i1
        285, // float_conv_to_i2
        286, // float_conv_to_i4
        287, // float_conv_to_i8
        288, // float_conv_to_r4
        0,  // float_conv_to_r8
        289, // float_conv_to_u4
        290, // float_conv_to_u8
        291, // r4_neg
        0,  // r4_not
        292, // r4_conv_to_i1
        293, // r4_conv_to_i2
        294, // r4_conv_to_i4
        295, // r4_conv_to_i8
        296, // r4_conv_to_r4
        297, // r4_conv_to_r8
        298, // r4_conv_to_u4
        0,  // r4_conv_to_u8
        299, // float_conv_to_u2
        300, // float_conv_to_u1
        301, // float_conv_to_i
        302, // float_conv_to_ovf_i
        303, // float_conv_to_ovd_u
        0,  // float_add_ovf
        0,  // float_add_ovf_un
        304, // float_mul_ovf
        0,  // float_mul_ovf_un
        0,  // float_sub_ovf
        0,  // float_sub_ovf_un
        0,  // float_conv_to_ovf_i1_un
        0,  // float_conv_to_ovf_i2_un
        0,  // float_conv_to_ovf_i4_un
        0,  // float_conv_to_ovf_i8_un
        0,  // float_conv_to_ovf_u1_un
        0,  // float_conv_to_ovf_u2_un
        0,  // float_conv_to_ovf_u4_un
        0,  // float_conv_to_ovf_u8_un
        0,  // float_conv_to_ovf_i_un
        0,  // float_conv_to_ovf_u_un
        0,  // float_conv_to_ovf_i1
        0,  // float_conv_to_ovf_u1
        0,  // float_conv_to_ovf_i2
        0,  // float_conv_to_ovf_u2
        0,  // float_conv_to_ovf_i4
        0,  // float_conv_to_ovf_u4
        0,  // float_conv_to_ovf_i8
        0,  // float_conv_to_ovf_u8
        305, // float_ceq
        306, // float_cgt
        307, // float_cgt_un
        308, // float_clt
        309, // float_clt_un
        310, // float_cneq
        311, // float_cge
        312, // float_cle
        313, // float_ceq_membase
        314, // float_cgt_membase
        315, // float_cgt_un_membase
        316, // float_clt_membase
        317, // float_clt_un_membase
        318, // float_conv_to_u
        319, // ckfinite
        320, // r4_conv_to_u2
        321, // r4_conv_to_u1
        322, // r4_conv_to_i
        0,  // r4_conv_to_ovf_i
        0,  // r4_conv_to_ovd_u
        0,  // r4_add_ovf
        0,  // r4_add_ovf_un
        0,  // r4_mul_ovf
        0,  // r4_mul_ovf_un
        0,  // r4_sub_ovf
        0,  // r4_sub_ovf_un
        0,  // r4_conv_to_ovf_i1_un
        0,  // r4_conv_to_ovf_i2_un
        0,  // r4_conv_to_ovf_i4_un
        0,  // r4_conv_to_ovf_i8_un
        0,  // r4_conv_to_ovf_u1_un
        0,  // r4_conv_to_ovf_u2_un
        0,  // r4_conv_to_ovf_u4_un
        0,  // r4_conv_to_ovf_u8_un
        0,  // r4_conv_to_ovf_i_un
        0,  // r4_conv_to_ovf_u_un
        0,  // r4_conv_to_ovf_i1
        0,  // r4_conv_to_ovf_u1
        0,  // r4_conv_to_ovf_i2
        0,  // r4_conv_to_ovf_u2
        0,  // r4_conv_to_ovf_i4
        0,  // r4_conv_to_ovf_u4
        0,  // r4_conv_to_ovf_i8
        0,  // r4_conv_to_ovf_u8
        323, // r4_ceq
        324, // r4_cgt
        325, // r4_cgt_un
        326, // r4_clt
        327, // r4_clt_un
        328, // r4_cneq
        329, // r4_cge
        330, // r4_cle
        0,  // float_getlow32
        0,  // float_gethigh32
        331, // jump_table
        332, // aotconst
        0,  // patch_info
        0,  // got_entry
        333, // call_handler
        334, // start_handler
        335, // endfilter
        336, // endfinally
        337, // get_ex_obj
        0,  // bigmul
        0,  // bigmul_un
        338, // int_min_un
        339, // int_max_un
        340, // long_min_un
        341, // long_max_un
        0,  // min
        0,  // max
        342, // int_min
        343, // int_max
        344, // long_min
        345, // long_max
        0,  // rmax
        0,  // rmin
        0,  // rpow
        0,  // fmax
        0,  // fmin
        0,  // fpow
        0,  // rcopysign
        0,  // fcopysign
        346, // adc
        347, // adc_imm
        348, // sbb
        349, // sbb_imm
        350, // addcc
        0,  // addcc_imm
        351, // subcc
        0,  // subcc_imm
        352, // br_reg
        353, // sext_i1
        354, // sext_i2
        355, // sext_i4
        0,  // zext_i1
        0,  // zext_i2
        356, // zext_i4
        0,  // cne
        0,  // trunc_i4
        0,  // add_ovf_carry
        0,  // sub_ovf_carry
        0,  // add_ovf_un_carry
        0,  // sub_ovf_un_carry
        357, // laddcc
        358, // lsubcc
        359, // sin
        360, // cos
        361, // abs
        362, // tan
        363, // atan
        364, // sqrt
        0,  // round
        0,  // ceil
        0,  // floor
        0,  // fma
        0,  // sinf
        0,  // cosf
        0,  // expf
        0,  // exp
        0,  // log
        0,  // log2
        0,  // log2f
        0,  // log10
        0,  // log10f
        0,  // trunc
        0,  // truncf
        0,  // absf
        0,  // sqrtf
        0,  // ceilf
        0,  // floorf
        0,  // fmaf
        0,  // acos
        0,  // sinh
        0,  // acosh
        0,  // asin
        0,  // asinh
        0,  // atanh2
        0,  // cbrt
        0,  // cosh
        0,  // tanh
        0,  // strlen
        0,  // newarr
        0,  // ldlen
        0,  // bounds_check
        0,  // isinst
        0,  // castclass
        0,  // ldelema2d
        0,  // memcpy
        0,  // memset
        0,  // save_lmf
        0,  // restore_lmf
        0,  // memmove
        365, // card_table_wbarrier
        366, // tls_get
        0,  // tls_get_reg
        367, // tls_set
        0,  // tls_set_reg
        0,  // load_gotaddr
        368, // dummy_use
        369, // not_reached
        370, // not_null
        371, // extract_i4
        372, // iconv_to_r4_raw
        373, // extract_i2
        374, // extract_u2
        375, // extract_i1
        376, // extract_u1
        0,  // extract_r4
        377, // extract_r8
        378, // extract_i8
        0,  // insert_i1
        379, // insert_i2
        0,  // insert_i4
        0,  // insert_i8
        0,  // insert_r4
        0,  // insert_r8
        380, // extractx_u2
        381, // insertx_u1_slow
        382, // insertx_i4_slow
        383, // insertx_r4_slow
        384, // insertx_r8_slow
        385, // insertx_i8_slow
        0,  // fconv_to_r4_x
        386, // fconv_to_r8_x
        387, // xconv_r8_to_i4
        388, // iconv_to_x
        0,  // expand_i1
        389, // expand_i2
        390, // expand_i4
        391, // expand_r4
        392, // expand_i8
        393, // expand_r8
        394, // addps
        395, // divps
        396, // mulps
        397, // subps
        398, // maxps
        399, // minps
        400, // compps
        401, // andps
        402, // andnps
        403, // orps
        404, // xorps
        405, // haddps
        406, // hsubps
        407, // addsubps
        408, // dupps_low
        409, // dupps_high
        410, // rsqrtps
        411, // sqrtps
        412, // rcpps
        413, // pshuflew_high
        414, // pshuflew_low
        415, // pshufled
        416, // shufps
        417, // shufpd
        418, // addpd
        419, // divpd
        420, // mulpd
        421, // subpd
        422, // maxpd
        423, // minpd
        424, // comppd
        425, // andpd
        426, // andnpd
        427, // orpd
        428, // xorpd
        429, // haddpd
        430, // hsubpd
        431, // addsubpd
        432, // duppd
        433, // sqrtpd
        434, // extract_mask
        435, // pand
        436, // pandn
        437, // por
        438, // pxor
        439, // paddb
        440, // paddw
        441, // paddd
        442, // paddq
        443, // psubb
        444, // psubw
        445, // psubd
        446, // psubq
        447, // pmaxb_un
        448, // pmaxw_un
        449, // pmaxd_un
        450, // pmaxb
        451, // pmaxw
        452, // pmaxd
        453, // pavgb_un
        454, // pavgw_un
        455, // pminb_un
        456, // pminw_un
        457, // pmind_un
        458, // pminb
        459, // pminw
        460, // pmind
        461, // pcmpeqb
        462, // pcmpeqw
        463, // pcmpeqd
        464, // pcmpeqq
        465, // pcmpgtb
        466, // pcmpgtw
        467, // pcmpgtd
        468, // pcmpgtq
        469, // psum_abs_diff
        470, // unpack_lowb
        471, // unpack_loww
        472, // unpack_lowd
        473, // unpack_lowq
        474, // unpack_lowps
        475, // unpack_lowpd
        476, // unpack_highb
        477, // unpack_highw
        478, // unpack_highd
        479, // unpack_highq
        480, // unpack_highps
        481, // unpack_highpd
        482, // packw
        483, // packd
        484, // packw_un
        485, // packd_un
        486, // paddb_sat
        487, // paddb_sat_un
        488, // paddw_sat
        489, // paddw_sat_un
        490, // psubb_sat
        491, // psubb_sat_un
        492, // psubw_sat
        493, // psubw_sat_un
        494, // pmulw
        495, // pmuld
        496, // pmulq
        497, // pmulw_high_un
        498, // pmulw_high
        499, // pshrw
        500, // pshrw_reg
        501, // psarw
        502, // psarw_reg
        503, // pshlw
        504, // pshlw_reg
        505, // pshrd
        506, // pshrd_reg
        507, // pshrq
        508, // pshrq_reg
        509, // psard
        510, // psard_reg
        511, // pshld
        512, // pshld_reg
        513, // pshlq
        514, // pshlq_reg
        515, // prefetch_membase
        516, // cvtdq2pd
        517, // cvtdq2ps
        518, // cvtpd2dq
        519, // cvtpd2ps
        520, // cvtps2dq
        521, // cvtps2pd
        522, // cvttpd2dq
        523, // cvttps2dq
        0,  // dpps
        0,  // sse_loadu
        0,  // sse_movmsk
        0,  // sse_store
        0,  // sse_stores
        0,  // sse_movs
        0,  // sse_movs2
        0,  // sse_movehl
        0,  // sse_movelh
        0,  // sse_unpacklo
        0,  // sse_unpackhi
        0,  // sse_shuffle
        0,  // sse_and
        0,  // sse_or
        0,  // sse_xor
        0,  // sse_andn
        0,  // sse_addss
        0,  // sse_subss
        0,  // sse_divss
        0,  // sse_mulss
        0,  // sse_cmpss
        0,  // sse_comiss
        0,  // sse_ucomiss
        0,  // sse_movss
        0,  // sse_movss_store
        0,  // sse_movhps_load
        0,  // sse_movlps_load
        0,  // sse_movhps_store
        0,  // sse_movlps_store
        0,  // sse_movntps
        0,  // sse_prefetcht0
        0,  // sse_prefetcht1
        0,  // sse_prefetcht2
        0,  // sse_prefetchnta
        0,  // sse_sqrtss
        0,  // sse_rsqrtss
        0,  // sse_rcpss
        0,  // sse_cvtsi2ss
        0,  // sse_cvtsi2ss64
        0,  // sse2_packus
        0,  // sse2_srli
        0,  // sse2_shuffle
        0,  // sse2_adds
        0,  // sse2_subs
        0,  // sse2_cmpsd
        0,  // sse2_comieq_sd
        0,  // sse2_comisd
        0,  // sse2_ucomisd
        0,  // sse2_addsd
        0,  // sse2_subsd
        0,  // sse2_divsd
        0,  // sse2_mulsd
        0,  // sse2_movd
        0,  // sse2_movq
        0,  // sse2_movupd
        0,  // sse2_pslldq
        0,  // sse2_psrldq
        0,  // sse2_psraw_imm
        0,  // sse2_psrad_imm
        0,  // sse2_psrlw_imm
        0,  // sse2_psrld_imm
        0,  // sse2_psrlq_imm
        0,  // sse2_pshufd
        0,  // sse2_pshufhw
        0,  // sse2_pshuflw
        0,  // sse2_shufpd
        0,  // sse2_movhpd_load
        0,  // sse2_movlpd_load
        0,  // sse2_movhpd_store
        0,  // sse2_movlpd_store
        0,  // sse2_sqrtsd
        0,  // sse2_cvtsi2sd
        0,  // sse2_cvtsi2sd64
        0,  // sse2_cvtsd2sd
        0,  // sse2_pmuludq
        0,  // sse2_maskmovdqu
        0,  // sse3_movddup
        0,  // sse3_movshdup
        0,  // sse3_movsldup
        0,  // sse3_movddup_mem
        0,  // ssse3_abs
        0,  // ssse3_shuffle
        0,  // ssse3_alignr
        524, // roundp
        0,  // rounds
        0,  // sse41_insert
        0,  // sse41_blendv
        0,  // sse41_blend
        0,  // sse41_loadant
        0,  // sse41_mul
        0,  // sse41_mullo
        0,  // sse_cvtii
        0,  // sse_dpps
        0,  // sse_dppd
        0,  // sse_mpsadbw
        0,  // pclmulqdq
        0,  // aes_keygen
        0,  // sse42_crc32
        0,  // sse42_crc64
        0,  // sse42_ptestc
        0,  // cttz32
        0,  // cttz64
        0,  // bextr32
        0,  // bextr64
        0,  // bzhi32
        0,  // bzhi64
        0,  // pext32
        0,  // pext64
        0,  // pdep32
        0,  // pdep64
        0,  // mulxh32
        0,  // mulxh64
        0,  // mulxhl32
        0,  // mulxhl64
        0,  // create_scalar_unsafe
        0,  // create_scalar
        525, // xmove
        526, // xzero
        527, // xones
        0,  // xphi
        528, // memory_barrier
        529, // atomic_load_i1
        530, // atomic_load_i2
        531, // atomic_load_i4
        532, // atomic_load_i8
        533, // atomic_load_u1
        534, // atomic_load_u2
        535, // atomic_load_u4
        536, // atomic_load_u8
        537, // atomic_load_r4
        538, // atomic_load_r8
        539, // atomic_store_i1
        540, // atomic_store_i2
        541, // atomic_store_i4
        542, // atomic_store_i8
        543, // atomic_store_u1
        544, // atomic_store_u2
        545, // atomic_store_u4
        546, // atomic_store_u8
        547, // atomic_store_r4
        548, // atomic_store_r8
        549, // atomic_add_i4
        550, // atomic_add_i8
        0,  // atomic_and_i4
        0,  // atomic_and_i8
        0,  // atomic_or_i4
        0,  // atomic_or_i8
        551, // atomic_exchange_i4
        552, // atomic_exchange_i8
        553, // atomic_cas_i4
        554, // atomic_cas_i8
        555, // cmov_ieq
        556, // cmov_ige
        557, // cmov_igt
        558, // cmov_ile
        559, // cmov_ilt
        560, // cmov_ine_un
        561, // cmov_ige_un
        562, // cmov_igt_un
        563, // cmov_ile_un
        564, // cmov_ilt_un
        565, // cmov_leq
        566, // cmov_lge
        567, // cmov_lgt
        568, // cmov_lle
        569, // cmov_llt
        570, // cmov_lne_un
        571, // cmov_lge_un
        572, // cmov_lgt_un
        573, // cmov_lle_un
        574, // cmov_llt_un
        575, // liverange_start
        576, // liverange_end
        577, // gc_liveness_def
        578, // gc_liveness_use
        579, // gc_spill_slot_liveness_def
        580, // gc_param_slot_liveness_def
        581, // gc_safe_point
        582, // generic_class_init
        583, // x86_test_null
        584, // x86_compare_membase_reg
        585, // x86_compare_membase_imm
        0,  // x86_compare_mem_imm
        586, // x86_compare_membase8_imm
        587, // x86_compare_reg_membase
        588, // x86_inc_reg
        589, // x86_inc_membase
        590, // x86_dec_reg
        591, // x86_dec_membase
        592, // x86_add_membase_imm
        593, // x86_sub_membase_imm
        594, // x86_and_membase_imm
        595, // x86_or_membase_imm
        596, // x86_xor_membase_imm
        597, // x86_add_membase_reg
        598, // x86_sub_membase_reg
        599, // x86_and_membase_reg
        600, // x86_or_membase_reg
        601, // x86_xor_membase_reg
        602, // x86_mul_membase_reg
        603, // x86_add_reg_membase
        604, // x86_sub_reg_membase
        605, // x86_mul_reg_membase
        606, // x86_and_reg_membase
        607, // x86_or_reg_membase
        608, // x86_xor_reg_membase
        609, // x86_push_membase
        610, // x86_push_imm
        611, // x86_push
        612, // x86_push_obj
        0,  // x86_push_got_entry
        613, // x86_lea
        614, // x86_lea_membase
        615, // x86_xchg
        616, // x86_fpop
        0,  // x86_fp_load_i8
        0,  // x86_fp_load_i4
        617, // x86_seteq_membase
        0,  // x86_setne_membase
        0,  // x86_fxch
        0,  // x86_bsf32
        0,  // x86_bsr32
        0,  // x86_bsf64
        0,  // x86_bsr64
        618, // amd64_test_null
        619, // amd64_set_xmmreg_r4
        620, // amd64_set_xmmreg_r8
        621, // amd64_icompare_membase_reg
        622, // amd64_icompare_membase_imm
        623, // amd64_icompare_reg_membase
        624, // amd64_compare_membase_reg
        625, // amd64_compare_membase_imm
        626, // amd64_compare_reg_membase
        627, // amd64_add_membase_reg
        628, // amd64_sub_membase_reg
        629, // amd64_and_membase_reg
        630, // amd64_or_membase_reg
        631, // amd64_xor_membase_reg
        632, // amd64_mul_membase_reg
        633, // amd64_add_membase_imm
        634, // amd64_sub_membase_imm
        635, // amd64_and_membase_imm
        636, // amd64_or_membase_imm
        637, // amd64_xor_membase_imm
        0,  // amd64_mul_membase_imm
        638, // amd64_lea_membase
        639, // amd64_add_reg_membase
        640, // amd64_sub_reg_membase
        641, // amd64_and_reg_membase
        642, // amd64_or_reg_membase
        643, // amd64_xor_reg_membase
        0,  // amd64_mul_reg_membase
        644, // amd64_loadi8_memindex
        645, // amd64_save_sp_to_lmf
        0,  // llvm_outarg_vt
        0,  // objc_get_selector
        0,  // get_sp
        0,  // set_sp
        646, // get_last_error
        647, // fill_prof_call_ctx
        0,  // xequal
        0,  // xcompare
        0,  // xcompare_fp
        0,  // xbinop
        0,  // xop
        0,  // xop_x_i
        0,  // xop_x_x
        0,  // xop_i4_x
        0,  // xop_i4_x_x
        0,  // xop_i8_x
        0,  // xop_x_x_x
        0,  // xop_x_x_i4
        0,  // xop_x_x_i8
        0,  // xop_i4_i8
        0,  // xop_i8_i8
        0,  // xop_i4_i4
        0,  // xop_i4_i4_i4
        0,  // xop_i4_i4_i8
        0,  // xop_x_x_x_x
        0,  // xcast
        0,  // xextract_i32
        0,  // xextract_i64
        0,  // xextract_r8
        0,  // xextract_r4
        0,  // xinsert_i1
        0,  // xinsert_i2
        0,  // xinsert_i4
        0,  // xinsert_i8
        0,  // xinsert_r4
        0,  // xinsert_r8
        648, // lzcnt32
        649, // lzcnt64
        650, // popcnt32
        651, // popcnt64
        0,  // lscnt32
        0,  // lscnt64
        0,  // arm64_smulh
        0,  // arm64_umulh
};

