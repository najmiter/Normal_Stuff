include irvine32.inc
.data
	s3748359_1	db	10, 9, 9, 124, 124, 45, 45, 45, 45, 62, 32, 87, 101, 108, 99, 111, 109, 101, 0
	s3748359_2	db	32, 116, 111, 32, 116, 104, 101, 32, 115, 101, 99, 114, 101, 116, 32, 65, 76, 73, 69, 78, 32, 108, 97, 98, 32, 60, 45, 45, 45, 45, 124, 124, 0
	s3748359_3	db	10, 9, 9, 124, 124, 45, 45, 45, 45, 62, 32, 108, 107, 110, 32, 101, 115, 107, 97, 32, 107, 114, 111, 32, 103, 121, 32, 107, 121, 97, 32, 63, 33, 32, 60, 45, 45, 45, 45, 124, 124, 0
	
	int1359		db	10, 10, 9, 9, "Enter the radius of the pyramid:> ", 0
	space	db	" ", 0
	star	db	"*", 0
	tabs	db	9, 9, 0
	lines	db	10, 10, 0

	_radius_	dd	?

.code
main proc
	mov edx, offset s3748359_1
	call writestring
	mov edx, offset s3748359_2
	call writestring
	mov edx, offset int1359
	call writestring

	call readdec
	mov _radius_, eax

	mov ecx, _radius_
	mov edi, 0

	mov edx, offset lines
	call writestring

	.while ecx > 0
		mov edx, offset tabs
		call writestring
		mov eax, _radius_
		add eax, edi
		
		mov ebx, 0
		.while ebx <= eax
			.if ebx < ecx
				mov edx, offset space
			.else
				mov edx, offset star
			.endif
			
			call writestring
			inc ebx

		.endw
		call crlf
		inc edi
		dec ecx
	.endw

	_out_:
		mov edx, offset s3748359_3
		call writestring
		call readchar

exit
main endp
end main
