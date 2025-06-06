; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py UTC_ARGS: --version 5
; RUN: llc < %s -mtriple=avr -mattr=+movw | FileCheck %s --check-prefix=MOVW
; RUN: llc < %s -mtriple=avr -mattr=-movw | FileCheck %s --check-prefix=NOMOVW

define i16 @food(ptr %this) {
; MOVW-LABEL: food:
; MOVW:       ; %bb.0: ; %entry
; MOVW-NEXT:    movw r30, r24
; MOVW-NEXT:    ldd r24, Z+25
; MOVW-NEXT:    clr r25
; MOVW-NEXT:    ldd r18, Z+26
; MOVW-NEXT:    clr r19
; MOVW-NEXT:    sub r24, r18
; MOVW-NEXT:    sbc r25, r19
; MOVW-NEXT:    andi r24, 63
; MOVW-NEXT:    andi r25, 0
; MOVW-NEXT:    ret
;
; NOMOVW-LABEL: food:
; NOMOVW:       ; %bb.0: ; %entry
; NOMOVW-NEXT:    mov r30, r24
; NOMOVW-NEXT:    mov r31, r25
; NOMOVW-NEXT:    ldd r24, Z+25
; NOMOVW-NEXT:    clr r25
; NOMOVW-NEXT:    ldd r18, Z+26
; NOMOVW-NEXT:    clr r19
; NOMOVW-NEXT:    sub r24, r18
; NOMOVW-NEXT:    sbc r25, r19
; NOMOVW-NEXT:    andi r24, 63
; NOMOVW-NEXT:    andi r25, 0
; NOMOVW-NEXT:    ret
entry:
  %_rx_buffer_head = getelementptr inbounds nuw i8, ptr %this, i16 25
  %0 = load volatile i8, ptr %_rx_buffer_head
  %conv = zext i8 %0 to i16
  %_rx_buffer_tail = getelementptr inbounds nuw i8, ptr %this, i16 26
  %1 = load volatile i8, ptr %_rx_buffer_tail
  %conv2 = zext i8 %1 to i16
  %sub = sub nsw i16 %conv, %conv2
  %rem = and i16 %sub, 63
  ret i16 %rem
}

define i16 @fooe(i8 %a) {
; MOVW-LABEL: fooe:
; MOVW:       ; %bb.0:
; MOVW-NEXT:    clr r25
; MOVW-NEXT:    subi r24, 0
; MOVW-NEXT:    sbci r25, 1
; MOVW-NEXT:    andi r24, 1
; MOVW-NEXT:    andi r25, 0
; MOVW-NEXT:    ret
;
; NOMOVW-LABEL: fooe:
; NOMOVW:       ; %bb.0:
; NOMOVW-NEXT:    clr r25
; NOMOVW-NEXT:    subi r24, 0
; NOMOVW-NEXT:    sbci r25, 1
; NOMOVW-NEXT:    andi r24, 1
; NOMOVW-NEXT:    andi r25, 0
; NOMOVW-NEXT:    ret
  %1 = zext i8 %a to i16
  %2 = sub i16 %1, 256
  %3 = and i16 %2, 1
  ret i16 %3
}
