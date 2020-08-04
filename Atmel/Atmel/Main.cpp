/*
 * AVM5.asm - Program which clears the display buffers  for the LCD DOG.
 *        The cleared buffers are then output onto the LCD DOG through PORT B.
 *        Then the freq_meas_1secgate subroutine is called which counts the 
 *        total number of positive edges of a waveform over the course of one
 *        second. The registers containing the total number of positive edges
 *        are then returned to the main function where the values are unpacked
 *        and output to the LCD DOG. The waveform will be read and updated
 *        approximately every second and a new frequency value will be output
 *        according to the amount of positive edges detected on the waveform. In order 
 *        for the subroutine to run for exactly one second while still measuring positive
 *        edges, TC1 is utilized in order to accurately measure the waveforms.
 *        
 *
 *    inputs: PB1, PB2, PB3, PB4, PB5 (pushbuttons), PD0 to PD7
 *        
 *
 *    outputs: LCD DOG, PB0 to PB7, PA0 to PA6
 *        
 *
 *    assumes: initialized LCD DOG, internal 10-bit ADC, 0-5V range, 2.56V reference
 *    alters: r8, r9, r16, r17, r18, r19, r20, r21, r25, Y register, Z register,
 *     stack, SREG
 *
 *  Created: 11/20/2014 10:24:12 AM
*   Author: Daniel Peterson
 *     Lab 10
 *     Section 3
 *     Bench 2
 *     Version 1.1
 */ 

     .org $00
    rjmp start                ;reset vector (MCU reset)


    .org $02
    rjmp isr_PB
//    .org $1C
//    rjmp isr_adc_complete
//    .org $14
//    rjmp SPI_complete

    .nolist
    .include "m16def.inc"
    rjmp start
    .include "lcd_dog_asm_driver_m16A.inc"
    .list


start:

    ldi r16, LOW (RAMEND)        ;load SPL with the low byte of
    out SPL, r16                ;RAMEND address
    ldi r16, HIGH (RAMEND)        ;load SPH with the high byte of
    out SPH, r16                ;RAMEND address'

    ; Port A configuration
    ldi r16, $FF                ;configure port A as an
    out DDRA, r16                ;output port (not PA7)
    ldi r16, $FF                ;initialize internal pullups
    out PORTA, r16                ;for PORT A

    ; Port B configuration
    ldi r16, $FF                ;configure port B as an
    out DDRB, r16                ;output port
    //ldi r16, $FF
    //out PORTB, r16

    ; Port C configuration
    ldi r16, $FF                ;initialize internal pullups
    out PORTC, r16                ;for PORT C
    ldi r16, $01                ;configure port C as an
    out DDRC, r16                ;input port (not PC0)

    ; Port D configuration
    ldi r16, $FF                ;initialize internal pullups
    out PORTD, r16                ;for PORT D
    ldi r16, $00                ;configure port D as an
    out DDRD, r16                ;input port


    ldi r16, 1 << INT0
    out GICR, r16
    ldi r16, $03
    out MCUCR, r16
ldi r16, $00
mov r0, r16
    sei

    //ldi r16, 1 << REFS1 | 1 << REFS0 | 1 << ADLAR | 0 << MUX3 | 1 << MUX2 | 0 << MUX1 | 0 << MUX0
    //out ADMUX, r16                    ;use internal 2.56V reference and align bits to left
    //ldi r16, 1 << ADEN | 1 << ADPS2 | 0 << ADPS1 | 0 << ADPS0    ;ADEN has ADC consume power when on
    //out ADCSRA, r16                    ;enable the ADC and start converting


reset:

    rcall init_lcd_dog            ; init display, using SPI serial interface

lcd_display_diag:
   
    rcall clr_dsp_buffs            ; clear all three display lines
    rcall update_lcd_dog        ;

basic_dsp_diag_one:
   
    rcall clr_dsp_buffs            ;clears the display

     
updating_stuff:

    ldi   r20, 48                    ; total length of all display buffers.
    ldi   ZH, high(dsp_buff_1)        ; init pointer to 1st byte of
    ldi   ZL, low(dsp_buff_1)        ; buffer-1
    
    ldi r16, $00
    mov r0, r16

write_loop:         
    clt

/////////////////////////////////////////////////INSERT MENU CODE//////////////////////////////////////////////////////////////////////

//rjmp write_loop
/*
  ldi r16, 'R'                ;load ASCII 'A'
  sts dsp_buff_3+0, r16        ;store in SRAM
  ldi r16, 'U'                ;load ASCII 'u'
  sts dsp_buff_3+1, r16        ;store in SRAM
  ldi r16, 'N'                ;load ASCII 't'
  sts dsp_buff_3+2, r16        ;store in SRAM
  */
run:
  ldi r16, 'V'  
        sts dsp_buff_1+9, r16        ;store in SRAM
        ldi r16, 'D'  
        sts dsp_buff_1+10, r16        ;store in SRAM
        ldi r16, 'C'  
        sts dsp_buff_1+11, r16        ;store in SRAM


ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+1, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+2, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+3, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+4, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+5, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+6, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+7, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+8, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+9, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+10, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+11, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+12, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+13, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+14, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+15, r16        ;store in SRAM
ldi r16, 'A'                ;load ASCII 'E'
        sts dsp_buff_3+11, r16        ;store in SRAM
        ldi r16, 'V'                ;load ASCII 'V'
        sts dsp_buff_3+12, r16        ;store in SRAM
        ldi r16, 'M'                ;load ASCII 'M'
        sts dsp_buff_3+13, r16        ;store in SRAM
        ldi r16, '5'                ;load ASCII '1'
        sts dsp_buff_3+14, r16        ;store in SRAM
        ldi r16, ' '                ;load ASCII 'a'
        sts dsp_buff_3+15, r16        ;store in SRAM
rcall update_lcd_dog

    rcall read_adc
  //   ldi r16, $C0
   // mov r8, r16
   // ldi r16, $F4
   // mov r9, r16

 mov r17, r19            ;SPI Data MSB
    andi r17, $0F
    swap r17
    mov r16, r18
andi r16, $F0
swap r16
add r17, r16
mov r16, r8
andi r16, $0F
   ldi r18, 16
   ldi r19, $00
//    ldi r18, 20    
            //ldi r19, $00
            //ldi r17, $80
    rcall mpy16u
    mov r4, r21            ;MSB
    mov r3, r20
    mov r2, r19
    mov r1, r18            ;LSB
 /*   ldi r22, 10
    ldi r23, $00
    ldi r24, $00
    ldi r25, $00
    rcall div32u
    mov r4, r21            ;MSB
    mov r3, r20
    mov r2, r19
    mov r1, r18            ;LSB
   */ mov r16, r19
    mov r17, r20
    rcall bin2bcd16
    mov r25, r15
    mov r24, r14
    mov r23, r13
    rcall unpack_BCD
    //mov r16, r20
    //mov r17, r21
    //rcall bin2bcd16
    //rcall unpack_BCD
   ldi r16, 'R'                ;load ASCII 'A'
  sts dsp_buff_3+0, r16        ;store in SRAM
  ldi r16, 'U'                ;load ASCII 'u'
  sts dsp_buff_3+1, r16        ;store in SRAM
  ldi r16, 'N'                ;load ASCII 't'
  sts dsp_buff_3+2, r16        ;store in SRAM
ldi r16, ' '
 sts dsp_buff_3+3, r16        ;store in SRAM
ldi r16, ' '
 sts dsp_buff_3+4, r16        ;store in SRAM
ldi r16, ' '
 sts dsp_buff_3+5, r16        ;store in SRAM
ldi r16, ' '
 sts dsp_buff_3+6, r16        ;store in SRAM

   
  hold_stuff:
        //mov r16, r15
        //sts dsp_buff_1+4, r16        ;store in SRAM
        mov r16, r14
        sts dsp_buff_1+4, r16        ;store in SRAM
        ldi r16, '.'
        sts dsp_buff_1+5, r16        ;store in SRAM
        mov r16, r9
        sts dsp_buff_1+6, r16        ;store in SRAM
        mov r16, r13
        sts dsp_buff_1+7, r16        ;store in SRAM
        mov r16, r8
        sts dsp_buff_1+8, r16        ;store in SRAM
       /* ldi r16, 'V'  
        sts dsp_buff_1+9, r16        ;store in SRAM
        ldi r16, 'D'  
        sts dsp_buff_1+10, r16        ;store in SRAM
        ldi r16, 'C'  
        sts dsp_buff_1+11, r16        ;store in SRAM

        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+4, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+5, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+6, r16        ;store in SRAM
        ldi r16, 'E'                ;load ASCII 'E'
        sts dsp_buff_3+11, r16        ;store in SRAM
        ldi r16, 'V'               ;load ASCII 'V'
        sts dsp_buff_3+12, r16        ;store in SRAM
        ldi r16, 'M'                ;load ASCII 'M'
        sts dsp_buff_3+13, r16        ;store in SRAM
        ldi r16, '1'                ;load ASCII '1'
        sts dsp_buff_3+14, r16        ;store in SRAM
        ldi r16, 'b'                ;load ASCII 'a'
        sts dsp_buff_3+15, r16        ;store in SRAM
      */  rcall update_lcd_dog
//rcall isr_PB

  //  brts hold_stuff
    rjmp run			;refresh the loop

 

    ;************************
    ;NAME:      clr_dsp_buffs
    ;FUNCTION:  Initializes dsp_buffers 1, 2, and 3 with blanks (0x20)
    ;ASSUMES:   Three CONTIGUOUS 16-byte dram based buffers named
    ;           dsp_buff_1, dsp_buff_2, dsp_buff_3.
    ;RETURNS:   nothing.
    ;MODIFIES:  r25,r26, Z-ptr
    ;CALLS:     none
    ;CALLED BY: main application and diagnostics
    ;********************************************************************
clr_dsp_buffs:
     ldi R25, 48               ; load total length of both buffer.
     ldi R26, ' '              ; load blank/space into R26.
     ldi ZH, high (dsp_buff_1) ; Load ZH and ZL as a pointer to 1st
     ldi ZL, low (dsp_buff_1)  ; byte of buffer for line 1.
   
    ;set DDRAM address to 1st position of first line.
store_bytes:
     st  Z+, R26       ; store ' ' into 1st/next buffer byte and
                       ; auto inc ptr to next location.
     dec  R25          ; 
     brne store_bytes  ; cont until r25=0, all bytes written.
     ret



    ;***************************************************************************
    ;*
    ;* "bin2BCD16" - 16-bit Binary to BCD conversion
    ;*
    ;* This subroutine converts a 16-bit number (fbinH:fbinL) to a 5-digit
    ;* packed BCD number represented by 3 bytes (tBCD2:tBCD1:tBCD0).
    ;* MSD of the 5-digit number is placed in the lowermost nibble of tBCD2.
    ;*
    ;* Number of words    :25
    ;* Number of cycles    :751/768 (Min/Max)
    ;* Low registers used    :3 (tBCD0,tBCD1,tBCD2)
    ;* High registers used  :4(fbinL,fbinH,cnt16a,tmp16a)    
    ;* Pointers used    :Z
    ;*
    ;***************************************************************************

;***** Subroutine Register Variables

.equ    AtBCD0    =13        ;address of tBCD0
.equ    AtBCD2    =15        ;address of tBCD1

.def    tBCD0    =r13        ;BCD value digits 1 and 0
.def    tBCD1    =r14        ;BCD value digits 3 and 2
.def    tBCD2    =r15        ;BCD value digit 4
.def    fbinL    =r16        ;binary value Low byte
.def    fbinH    =r17        ;binary value High byte
.def    cnt16a    =r18        ;loop counter
.def    tmp16a    =r19        ;temporary value

;***** Code

bin2BCD16:
    push r19
    push ZH
    push ZL
    ldi    cnt16a,16    ;Init loop counter    
    clr    tBCD2        ;clear result (3 bytes)
    clr    tBCD1        
    clr    tBCD0        
    clr    ZH            ;clear ZH (not needed for AT90Sxx0x)
bBCDx_1:
    lsl    fbinL    ;shift input value
    rol    fbinH        ;through all bytes
    rol    tBCD0        ;
    rol    tBCD1
    rol    tBCD2
    dec    cnt16a        ;decrement loop counter
    brne bBCDx_2    ;if counter not zero
    pop ZL
    pop ZH
    pop r19
    ret                ;   return

bBCDx_2:

    ldi    r30,AtBCD2+1    ;Z points to result MSB + 1

bBCDx_3:
    ld    tmp16a,-Z    ;get (Z) with pre-decrement
    subi    tmp16a,-$03    ;add 0x03
    sbrc    tmp16a,3    ;if bit 3 not clear
    st    Z,tmp16a    ;    store back
    ld    tmp16a,Z    ;get (Z)
    subi    tmp16a,-$30    ;add 0x30
    sbrc    tmp16a,7    ;if bit 7 not clear
    st    Z,tmp16a    ;    store back
    cpi    ZL,AtBCD0    ;done all three?
    brne    bBCDx_3        ;loop again if not
    rjmp    bBCDx_1        


unpack_BCD:
    push r16
    push r17
    push r18
    in r16, SREG
    ldi r16, $0F
    ldi r18, $0A
    mov r9, r14
    mov r8, r13
    swap r14
    swap r13
    and r8, r16
    cp r8, r18
    brlo numbers1
    rjmp hex1
n1:
    ldi r16, $0F
    and r9, r16
    cp r9, r18
    brlo numbers2
    rjmp hex2
n2:
    ldi r16, $0F
    and r13, r16
    cp r13, r18
    brlo numbers3
    rjmp hex3
n3:
    ldi r16, $0F
    and r14, r16
    cp r14, r18
    brlo numbers4
    rjmp hex4
numbers1:
    ldi r16, $30
    add r8, r16
    rjmp n1
numbers2:
    ldi r16, $30
    add r9, r16
    rjmp n2
numbers3:
    ldi r16, $30
    add r13, r16
    rjmp n3
numbers4:
    ldi r16, $30
    add r14, r16
final:
    ldi r16, $0F
    and r15, r16
    cp r15, r18
    brlo numbers5
    rjmp hex5
finish:
    out SREG,r16
    pop r18
    pop r17
    pop r16
    ret

hex1:
    ldi r17, $37
    add r8, r17
    rjmp n1
hex2:
    ldi r17, $37
    add r9, r17
    rjmp n2
hex3:
    ldi r17, $37
    add r13, r17
    rjmp n3
hex4:
    ldi r17, $37
    add r14, r17
    rjmp final
hex5:
    ldi r17, $37
    add r15, r17
    rjmp finish
numbers5:
    ldi r16, $30
    add r15, r16
    rjmp finish


read_adc:
ldi r16, (1<<7) | (1<<0)
out DDRB, r16
ldi r16, (1<<SPE) | (1<<MSTR) | (1<<SPR1)
out SPCR, r16

start_high:
cbi PORTB, 0
ldi r16, $FF
out SPDR, r16

high_byte:
sbis SPSR, SPIF
rjmp high_byte
in r19, SPDR
andi r19, $0F

start_low:
ldi r16, $FF
out SPDR, r16

low_byte:
sbis SPSR, SPIF
rjmp low_byte
in r18, SPDR
sbi PORTB, 0

/*compare_high:
cpi r19, $00
brne start_high

compare_low:
cpi r18, 100
brne start_high

sbi PORTB, 0

capture:
rcall delay_40ms
rcall delay_40ms
rcall delay_40ms
rcall delay_40ms


cbi PORTB, 0
ldi r16, $FF
out SPDR, r16

high_byte1:
sbis SPSR, SPIF
rjmp high_byte1
in r19, SPDR
andi r19, $0F

ldi r16, $FF
out SPDR, r16

low_byte1:
sbis SPSR, SPIF
rjmp low_byte1
in r18, SPDR
sbi PORTB, 0

compare_high1:
cpi r19, $00
brne endadc

compare_low1:
cpi r18, 100
brlo capture
*/
endadc:
ldi r16, $FF
out DDRB, r16
//load new r19 value
//load new r18 value
//rcall tone_5V
//rcall update_lcd_dog
//rcall delay
ret


//SPI_complete:
    
//    in r9, SPDR
//    set
//    reti



;***************************************************************************
;*
;* "mpy16u" - 16x16 Bit Unsigned Multiplication
;*
;* This subroutine multiplies the two 16-bit register variables 
;* r19:r18 and r17:r16.
;* The result is placed in m16u3:m16u2:r19:r18.
;*  
;* Number of words    :14 + return
;* Number of cycles    :153 + return
;* Low registers used    :None
;* High registers used  :7 (r18,r19,r16/r18,r17/r19,m16u2,
;*                          m16u3,mcnt16u)    
;*
;***************************************************************************

;***** Subroutine Register Variables
/*
.def    r16    =r16        ;multiplicand low byte
.def    r17    =r17        ;multiplicand high byte
.def    r18    =r18        ;multiplier low byte
.def    r19    =r19        ;multiplier high byte

.def    r18    =r18        ;result byte 0 (LSB)
.def    r19    =r19        ;result byte 1
*/
.def    m16u2    =r20        ;result byte 2
.def    m16u3    =r21        ;result byte 3 (MSB)
.def    mcnt16u    =r22        ;loop counter

;***** Code

mpy16u:    clr    m16u3        ;clear 2 highest bytes of result
    clr    m16u2
    ldi    mcnt16u,16    ;init loop counter
    lsr    r19
    ror    r18

m16u_1:    brcc    noad8        ;if bit 0 of multiplier set
    add    m16u2,r16    ;add multiplicand Low to byte 2 of res
    adc    m16u3,r17    ;add multiplicand high to byte 3 of res
noad8:    ror    m16u3        ;shift right result byte 3
    ror    m16u2        ;rotate right result byte 2
    ror    r19        ;rotate result byte 1 and multiplier High
    ror    r18        ;rotate result byte 0 and multiplier Low
    dec    mcnt16u        ;decrement loop counter
    brne    m16u_1        ;if not done, loop more
    ret


;***************************************************************************
;*
;* "div32u" - 32/32 Bit Unsigned Division
;*
;* Ken Short
;*
;* This subroutine divides the two 32-bit numbers 
;* "r21:r20:r19:r18" (dividend) and "r25:r24:r25:r24"
;* (divisor). 
;* The result is placed in "r21:r20:r21:r20" and the
;* remainder in "r15:r14:r15:r14".
;*  
;* Number of words    :
;* Number of cycles    :655/751 (Min/Max) ATmega16
;* #Low registers used    :2 (drem16uL,drem16uH)
;* #High registers used  :5 (dres16uL/dd16uL,dres16uH/dd16uH,dv16uL,dv16uH,
;*                dcnt16u)
;* A $0000 divisor returns $FFFF
;*
;***************************************************************************

;***** Subroutine Register Variables

/*.def    r12=r12    ;remainder
.def    r13=r13
.def    r14=r14
.def    r15=r15

.def    r18=r18    ;result (quotient)
.def    r19=r19
.def    r20=r20
.def    r21=r21

.def    r18    =r18    ;dividend
.def    r19    =r19
.def    r20    =r20
.def    r21    =r21

.def    r22    =r22    ;divisor
.def    r23    =r23
.def    r24    =r24
.def    r25    =r25

.def    r17    =r17
*/
;***** Code

div32u:
    clr    r12    ;clear remainder Low byte
    clr r13
    clr r14
    sub    r15,r15;clear remainder High byte and carry
    ldi    r17,33    ;init loop counter
d32u_1:
    rol    r18        ;shift left dividend
    rol    r19
    rol    r20    
    rol    r21
    dec    r17        ;decrement counter
    brne    d32u_2        ;if done

    mov r4, r21
    mov r3, r20
    mov r2, r19
    mov r1, r18
    mov r8, r15
    mov r7, r14
    mov r6, r13
    mov r5, r12
    ret            ;    return
d32u_2:
    rol    r12    ;shift dividend into remainder
    rol    r13
    rol    r14
    rol    r15

    sub    r12,r22    ;remainder = remainder - divisor
    sbc    r13,r23
    sbc    r14,r24
    sbc    r15,r25    ;
    brcc    d32u_3        ;   branch if reult is pos or zero

    add    r12,r22    ;    if result negative restore remainder
    adc    r13,r23
    adc    r14,r24
    adc    r15,r25
    clc            ;    clear carry to be shifted into result
    rjmp    d32u_1        ;else
d32u_3:    sec            ;    set carry to be shifted into result
    rjmp    d32u_1






isr_PB:
        push r18            ;save r18
        push r16            ;save r16
      //  in r16, SREG        ;save...
      //  push r16            ;SREG
        push r17            ;save r17
        in r16, PIND        ;read the values of PORT-D
        andi r16, $E0        ;keep only PD5 and PD6
        mov r18, r16        ;seed PD5 & PD6 pre-debounce
        //in r16, PIND
        //andi r16, $80
        //mov r19, r16
//ldi r18, $00
        //start 10ms loop
        ldi r16, $9D        ;outer 10ms delay loop
delay_10ms:
        ldi r17, $0F        ;inner loop counter
here:
        dec r17                ;decrement the inner loop
        nop                    ;delay
        brne here            ;if r17 isnt zero, inner loop repeat
        dec r16                ;decrement the outer loop
        nop                    ;delay
        brne delay_10ms        ;if r16 isnt zero, outer loop repeat
        nop                    ;delay
        nop                    ;delay
        //end of delay loop
        in r16, PIND        ;read post-debounce PORT-D
        andi r16, $E0        ;keep only PD5 and PD6
        cp r18, r16            ;compare old vs new
        brne done1            ;if !=, debounce occured. end
        sbic PIND, 7        ;if bit 7 set (LF not pressed), skip
		rjmp displaymodes

displaymodes:
	


    checkright:
        in r16, PIND
        andi r16, $60
        cp r18, r16
        brne done1
        sbic PIND, 6
        rjmp checkleft
        rjmp toggleright
    checkleft:
        in r16, PIND
        andi r16, $60
        cp r19, r16
        brne done1
        sbic PIND, 5
        rjmp done
        rjmp toggleleft

toggleleft:
    ldi r16, $00
    cp r0, r16
    breq adding1
    rjmp lowerbits
adding2:
    com r5
    ldi r17, $01
    and r5, r17
    ldi r16, $00
    cp r5, r16
    brne captureset
    rjmp lowerbits

done1:
    rjmp done

toggleright:
    ldi r16, $01
    cp r0, r16
    breq adding1
    rjmp lowerbits
adding1:
    com r5
    ldi r17, $01
    and r5, r17
    ldi r16, $00
    cp r5, r16
    brne captureset
    rjmp lowerbits


captureset:

rcall tone_5V
rcall capture2
rcall capture
rjmp transformdata
   
transformdata:

 mov r17, r19            ;SPI Data MSB
    andi r17, $0F
    swap r17
    mov r16, r18
andi r16, $F0
swap r16
add r17, r16
mov r16, r8
andi r16, $0F
    ldi r18, 16
  
    ldi r19, $00

    rcall mpy16u
    mov r4, r21            ;MSB
    mov r3, r20
    mov r2, r19
    mov r1, r18            ;LSB

    mov r16, r19
    mov r17, r20
    rcall bin2bcd16
    mov r25, r15
    mov r24, r14
    mov r23, r13
    rcall unpack_BCD
  
        //mov r16, r15
        //sts dsp_buff_1+4, r16        ;store in SRAM
        mov r16, r14
        sts dsp_buff_1+4, r16        ;store in SRAM
        ldi r16, '.'
        sts dsp_buff_1+5, r16        ;store in SRAM
        mov r16, r9
        sts dsp_buff_1+6, r16        ;store in SRAM
        mov r16, r13
        sts dsp_buff_1+7, r16        ;store in SRAM
        mov r16, r8
        sts dsp_buff_1+8, r16        ;store in SRAM
/*        
ldi r16, 'V' 
        sts dsp_buff_1+9, r16        ;store in SRAM
        ldi r16, 'D' 
        sts dsp_buff_1+10, r16        ;store in SRAM
        ldi r16, 'C' 
        sts dsp_buff_1+11, r16        ;store in SRAM


ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+1, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+2, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+3, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+4, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+5, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+6, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+7, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+8, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+9, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+10, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+11, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+12, r16        ;store in SRAM
ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+13, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+14, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+15, r16        ;store in SRAM*/
   ldi r16, 'C'                ;load ASCII 'A'
  sts dsp_buff_3+0, r16        ;store in SRAM
  ldi r16, 'a'                ;load ASCII 'u'
  sts dsp_buff_3+1, r16        ;store in SRAM
  ldi r16, 'p'                ;load ASCII 't'
  sts dsp_buff_3+2, r16        ;store in SRAM
  ldi r16, 't'                ;load ASCII 't'
  sts dsp_buff_3+3, r16        ;store in SRAM
  ldi r16, 'u'                ;load ASCII 't'
  sts dsp_buff_3+4, r16        ;store in SRAM
  ldi r16, 'r'                ;load ASCII 't'
  sts dsp_buff_3+5, r16        ;store in SRAM
  ldi r16, 'e'                ;load ASCII 't'
  sts dsp_buff_3+6, r16        ;store in SRAM

        rcall update_lcd_dog

ldi r17, $00
mov r16, r14
subi r16, $30
rcall send_audio_r17r16
rcall audelay_300mS
rcall audelay_300mS
rcall audelay_300mS
ldi r17, $00
ldi r16, $0A
rcall send_audio_r17r16
rcall audelay_300mS
rcall audelay_300mS
rcall audelay_300mS
ldi r17, $00
mov r16, r9
subi r16, $30
rcall audelay_300mS
rcall audelay_300mS
rcall audelay_300mS
rcall send_audio_r17r16
ldi r17, $00
mov r16, r13
subi r16, $30
rcall send_audio_r17r16
rcall audelay_300mS
rcall audelay_300mS
rcall audelay_300mS
ldi r17, $00
mov r16, r8
subi r16, $30
rcall send_audio_r17r16
rcall audelay_300mS
rcall audelay_300mS
rcall audelay_300mS

    rjmp captureset

lowerbits:
        com r0        ;SET register 30 bit 0 high (1) for 1 second
        ldi r17, $01
        and r0, r17
        ldi r16, $00
        cp r0, r16
        brne setting
        clt
ldi r16, 'R'                ;load ASCII 'A'
  sts dsp_buff_3+0, r16        ;store in SRAM
  ldi r16, 'U'                ;load ASCII 'u'
  sts dsp_buff_3+1, r16        ;store in SRAM
  ldi r16, 'N'                ;load ASCII 't'
  sts dsp_buff_3+2, r16        ;store in SRAM
ldi r16, ' '
sts dsp_buff_3+3, r16        ;store in SRAM
ldi r16, ' '
sts dsp_buff_3+4, r16        ;store in SRAM
ldi r16, ' '
sts dsp_buff_3+5, r16        ;store in SRAM
ldi r16, ' '
sts dsp_buff_3+6, r16        ;store in SRAM
        rjmp done
setting:
hold:
        set
        ldi r16, 'H'                ;load ASCII 'A'
        sts dsp_buff_3, r16        ;store in SRAM
        ldi r16, 'O'                ;load ASCII 'u'
        sts dsp_buff_3+1, r16        ;store in SRAM
        ldi r16, 'L'                ;load ASCII 't'
        sts dsp_buff_3+2, r16        ;store in SRAM
        ldi r16, 'D'                ;load ASCII 'o'
        sts dsp_buff_3+3, r16        ;store in SRAM
        ldi r16, ' '
sts dsp_buff_3+4, r16        ;store in SRAM
ldi r16, ' '
sts dsp_buff_3+5, r16        ;store in SRAM
ldi r16, ' '
sts dsp_buff_3+6, r16        ;store in SRAM


        //mov r16, r15
        //sts dsp_buff_1+4, r16        ;store in SRAM
        mov r16, r14
        sts dsp_buff_1+4, r16        ;store in SRAM
        ldi r16, '.'
        sts dsp_buff_1+5, r16        ;store in SRAM
        mov r16, r9
        sts dsp_buff_1+6, r16        ;store in SRAM
        mov r16, r13
        sts dsp_buff_1+7, r16        ;store in SRAM
        mov r16, r8
        sts dsp_buff_1+8, r16        ;store in SRAM
       /* ldi r16, 'V'  
        sts dsp_buff_1+9, r16        ;store in SRAM
        ldi r16, 'D'  
        sts dsp_buff_1+10, r16        ;store in SRAM
        ldi r16, 'C'  
        sts dsp_buff_1+11, r16        ;store in SRAM

        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+4, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+5, r16        ;store in SRAM
        ldi r16, '-'                ;load ASCII '-'
        sts dsp_buff_2+6, r16        ;store in SRAM
        ldi r16, 'E'                ;load ASCII 'E'
        sts dsp_buff_3+11, r16        ;store in SRAM
        ldi r16, 'V'               ;load ASCII 'V'
        sts dsp_buff_3+12, r16        ;store in SRAM
        ldi r16, 'M'                ;load ASCII 'M'
        sts dsp_buff_3+13, r16        ;store in SRAM
        ldi r16, '1'                ;load ASCII '1'
        sts dsp_buff_3+14, r16        ;store in SRAM
        ldi r16, 'b'                ;load ASCII 'a'
        sts dsp_buff_3+15, r16        ;store in SRAM
      */  rcall update_lcd_dog
//rcall isr_PB

    rjmp hold
//    rcall update_lcd_dog
//    rjmp setting
        rjmp done
done:
        pop r17
      //  pop r16
     //   out SREG, r16
        pop r16
        pop r18
      //  reti
ret


capture:

ldi r16, (1<<7) | (1<<0)
out DDRB, r16
ldi r16, (1<<SPE) | (1<<MSTR) | (1<<SPR1)
out SPCR, r16

rcall delay_40ms
rcall delay_40ms
rcall delay_40ms
rcall delay_40ms


cbi PORTB, 0
ldi r16, $FF
out SPDR, r16

high_byte1:
sbis SPSR, SPIF
rjmp high_byte1
in r19, SPDR
andi r19, $0F

ldi r16, $FF
out SPDR, r16

low_byte1:
sbis SPSR, SPIF
rjmp low_byte1
in r18, SPDR
sbi PORTB, 0

compare_high1:
cpi r19, $00
brne end1

compare_low1:
cpi r18, 100
brlo capture

end1:
ldi r16, $FF
out DDRB, r16
//load new r19 value
//load new r18 value
//rcall update_lcd_dog
rcall v_delay
ret



capture2:

ldi r16, (1<<7) | (1<<0)
out DDRB, r16
ldi r16, (1<<SPE) | (1<<MSTR) | (1<<SPR1)
out SPCR, r16

rcall delay_40ms
rcall delay_40ms
rcall delay_40ms
rcall delay_40ms


cbi PORTB, 0
ldi r16, $FF
out SPDR, r16

high_byte2:
sbis SPSR, SPIF
rjmp high_byte2
in r19, SPDR
andi r19, $0F

ldi r16, $FF
out SPDR, r16

low_byte2:
sbis SPSR, SPIF
rjmp low_byte2
in r18, SPDR
sbi PORTB, 0

compare_high2:
cpi r19, $00
brne capture2

compare_low2:
cpi r18, 100
brsh capture2

end3:
ldi r16, $FF
out DDRB, r16
//load new r19 value
//load new r18 value
//rcall tone_5V
//rcall update_lcd_dog
rcall tone_5V
rcall v_delay
ret



;*****************
;NAME:      tone_5V
;FUNCTION:  causes tone/beep on piezo element
;ASSUMES:   nothing
;RETURNS:   nothing
;MODIFIES:  SREG
;CALLS:     v_delay
;***************************************************************
tone_5V:
       push  r23   ; save registers
       push  r22
       push  r16

      ;********************************************
      ; SOUNDER TONE/DURATION ADJUSTMENT
      ; (May be adjusted by user, as needed)
      ldi   r16, 12     ; CALIBRATION PARAMETER
      ;********************************************
 
      ldi  r22, 0x04  ; inner delay count.
      ldi  r23, 1     ; outer delay count.
tone_loop:
      push r22        ; save counts in r22 and r23
      push r23        ;
      cbi  PortC,0    ; turn on sounder
      rcall v_delay   ; delay
      sbi  PortC,0    ; turn off sounder
      pop r23         ; restore delay count
      pop r22         ; down registers
      dec r16         ; adjust loop ctr, and if not
      brne tone_loop  ; zero, then branch and repeat.

      pop  r16   ; restore registers
      pop  r22
      pop  r23
      ret


 ;************************
; NAME: send_audio_r17r16
; DESC: Each call causes a 16 bit value to be transmitted to 
;   the audio playback module. The 16-bit value can range 
;   from 0x0000 to 0x01ff, providing for the playback of 
;   up to 512 .AD4 audio message files (AMFs). 
;
;  Currently: AMFs 0x0000 to 0x0009 are the matching
;     "number" audio files. So to output an audio "1", 
;     you load r17r16 with 0x0001.  To output an audio "2",
;     load r17:r16 withh 0x0002, and so on. See below for 
;     a full list presently available, pre-recorded
;     audio playback messages
;
; Interface signals:
;    DATA   = PA0    Data out to audio module.
;    DCLK   = PA1    Normally logic 1, Low for 2mS at start.
;    RESET  = PA2    Pulsed low, for 5mS, high for 300 mS
;                    before the clock goes low for 2mS.
;    BUSY   = PA3    Compicated signal!! (300mS delay required
;                    before testing this bit)
;                    1=processing data (busy), 0=ready for data
;
; Assumes: r17:r16 = trigger data to be serially sent. Sound 
;                    files available are as follows:
;
;    r17:r16 =  0x0000 = zero
;            =  0x0001 = one
;            =    0x0002 = two
;                  ...
;                  ...
;            =  0x0009 = nine
;            =  0x000a = 'point'
;            =
;-------------
; Inputs: r17:r16, PA3=Busy status bit
; Outputs: PA0=DATA; PA1=DCK; PA2=RESET (audio module)
; Notes: TIMING FOR THIS MODULE IS CRITICAL & IT IS
;        SUGGESTED THAT THE DELAY TIMES NOT BE ALTERED.
;
send_audio_r17r16:
check_busy:
     sbic  PinA, 3           ; if BUSY = 1... Wait!
     rjmp  check_busy    ;
     rcall audelay_10mS  ; **10mS**
check_busyy:
     sbic  PinA, 3           ; if BUSY = 1... Wait!
     rjmp  check_busyy   ;

reset_pulse:
     cbi  PortA, 2         ; take RESET of audmo low...
     rcall audelay_1mS     ; **10mS** must be low for > 5 mS,
     sbi  PortA, 2         ; take RESET back to '1'.

     ;audelay for 300mS before dclk goes low
     rcall audelay_300mS   ; REQ'D delay of 300mS
take_clk_low:
     cbi   PortA, 1        ; take DCLK low, and delay
     rcall audelay_1mS     ; **1mS** 

     ;send ZEROs loop
     ldi   r18, 0x010    ; load loop counter (16 clocks)
send_r17r16_loop:
     rol   r16           ; rotate and test next bit...
     rol   r17           ; (move bit into CY)
     brcs  out_one       ; if cy set, brch to output a '1'
     cbi   PortA, 0      ; OK... data bit is '0'
     rjmp  pulse_clk     ; jmp and gen clock pulse
out_one:
     sbi   PortA, 0      ; data bit is '1'
pulse_clk:
     cbi   PortA, 1      ; Take clk low, and
     rcall audelay_1mS   ; delay for 1mS
     sbi   PortA, 1      ; set clock bit high
     rcall audelay_1mS   ; delay for 2mS
     dec   r18           ; check loop counter &
     brne  send_r17r16_loop  ; jump if NOT zero

take_clk_data_high:
     sbi   PortA, 1      ; Take clk high, and
     sbi   PortA,0       ; take data high.
     rcall audelay_10mS  ; delay, and both
     rcall audelay_10mS  ; SEEM to be REQUIRED!
     ret 

 ;************************
;NAME:        audelay_30uS
;ASSUMES:     nothing
;RETURNS:     nothing
;MODIFIES:    SREG
;CALLED BY:   
;DESCRIPTION: This procedure will generate a fixed delay of just over
;             30 uS (assuming a 1 MHz clock).
;********************************************************************
audelay_30uS: nop               ; fine tune delay
     nop               ;
     push  r24         ; save count reg
     ldi   r24, 0x0f   ; load delay count.
aud30_loop:
     dec   r24         ; count down to
     brne  aud30_loop  ; zero.
     pop   r24         ; restore orig contents
     ret


;**************************
;NAME:        audelay_300uS
;ASSUMES:     nothing
;RETURNS:     nothing
;MODIFIES:    R25, SREG
;CALLED BY:   
;DESCRIPTION: This procedure will generate a fixed delay of APPROX
;             300 uS (assuming a 1 MHz clock).
;********************************************************************
audelay_300uS:
    ldi   r25, 10        ; loop count = 10 decimal
dly_300_loop:
    push  r25 
    rcall audelay_30uS
    pop   r25
    dec   r25            ; count down to
    brne  dly_300_loop   ; zero.
    ret


;*************************************************************
; audelay_1mS - Nested loop delay for creating a delay of 1 mS
; inputs: none
; outputs: none
; alters: nothing
;
; equates for this delay routine
.equ outer_cnt11 = 0x18  ; *20* worked (loop ctr val)
.equ inner_cnt11 = 0x0d  ; inner loop ctr load value
;
;****************************************************
audelay_1mS:
    push r16
    push r17
    ldi  r16,outer_cnt11   ;init outer loop counter value
dloop111:
    ldi  r17,inner_cnt11   ;init inner loop counter value
dloop222:
    dec  r17               ; decr inner count and if
    brne dloop222          ; 0, fall thru.
    dec r16                ; decr outer count, and if
    brne dloop111          ; 0, fall thru.
    pop  r17
    pop  r16
    ret       



;*************************************************************
; audelay_2mS - Nested loop delay for creating a delay of 2 mS
; inputs: none
; outputs: none
; alters: nothing
;
; equates for this delay routine
.equ outer_cnt2 = 0x33  ; outer loop counter load value
.equ inner_cnt2 = 0x0d  ; inner loop counter load value
;
;***********************************************
audelay_2mS:
    push r16
push r17
    ldi  r16,outer_cnt2   ;init outer loop counter value
dloop11:
    ldi  r17,inner_cnt2   ;init inner loop counter value
dloop22:
    dec  r17             ; decr inner count and if
    brne dloop22          ; 0, fall thru.
    dec r16              ; decr outer count, and if
    brne dloop11          ; 0, fall thru.
    pop  r17
    pop  r16
    ret       


;*********************************************************************
; audelay_10mS - Nested loop delay for creating a 10mS
;                (Useful for software debouncing)
;
; inputs: none
; outputs: none
; alters: nothing
;
; Debouncing delay equate counts
.equ o_cnt = 0xf1  ; outer loop counter load value
.equ i_cnt = 0x0d  ; inner loop counter load value
;
;***********************************************
audelay_10mS:
    push r16             ; save registers
    push r17
    ldi  r16,o_cnt   ; init outer loop counter value
audloop1:
    ldi  r17,i_cnt   ; init inner loop counter value
audloop2:
    dec  r17             ; decr inner count and if
    brne audloop2          ; 0, fall thru.
    dec r16              ; decr outer count, and if
    brne audloop1          ; 0, fall thru.
    pop  r17             ; restore registers
    pop  r16
    ret 



;************************
;NAME:        audelay_300mS
;ASSUMES:     nothing
;RETURNS:     nothing
;MODIFIES:    R22,R23, SREG
;CALLED BY:   init_dsp, ????
;DESCRIPTION: This procedure will generate a fixed delay of just over
;             300 mS.
;********************************************************************
audelay_300mS:
     ldi  r25, 27      ; outer loop ctr : *26* was min that worked
                       ; load count-down value for ~300mS
audelay_300ms_loop:
     push  r25           ; save loop counter
     rcall audelay_10mS  ; do a 10 mS delay, 35 times
     pop   r25           ; restore loop counter
     dec   r25           ; dec and check for 0
     brne  audelay_300ms_loop
     ret