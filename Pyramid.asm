include irvine32.inc
.data 
	in1msg	db	10, 9, 9, 124, 45, 45, 45, 62, 32, 87, 101, 108, 99, 111, 109, 101, 32, 116, 111, 32, 116, 104, 0
	in2msg	db	101, 32, 115, 101, 99, 114, 101, 116, 32, 65, 76, 73, 69, 78, 32, 108, 97, 98, 33, 32, 60, 45, 45, 45, 124, 10, 10, 0

	in3msg	db	9, 9, "Enter the radius of the Pyramid:> ", 0
	space	db	" ", 0
	star	db	"*", 0
	tabs	db	9, 9, 0
	lines	db	10, 10, 0

	_radius_	dd	?

.code 
	main proc
		mov edx, offset in1msg
		call writestring
		mov edx, offset in2msg
		call writestring
		mov edx, offset in3msg
		call writestring
		
		call readdec		; 5
		mov _radius_, eax

		mov ecx, _radius_	; ecx = 5

		mov edx, offset lines
		call writestring

		mov edi, 0
		.while ecx > 0							; 3 > 0
			mov edx, offset tabs
			call writestring

			mov eax, _radius_
			add eax, edi						; eax = 7

			mov ebx, 0
			.while ebx <= eax					; 0 <= 6
				.if ebx < ecx					; 0 < 3
					mov edx, offset space
				.else
					mov edx, offset star
				.endif

				call writestring
				inc ebx
			.endw

			call crlf
			inc edi								; 2
			dec ecx								; 3

		.endw

		_out_:
			mov edx, offset lines
			call writestring

			call readchar

	exit 
	main endp 
	end main
