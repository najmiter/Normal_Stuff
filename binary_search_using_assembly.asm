include irvine32.inc
.data
	sorted_array	dd	1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20

	found		db	"Data found", 10, 0
	not_found	db	"Data NOT found", 10, 0

	key			dd	5		; feel free to call the infamous USER to input for you
	_two_		dd	2

.code
main proc
	mov edi, key					; edi = key
	mov esi, 0					; Boolean { true if found | false if NOT found (initially false) }
	mov eax, ((lengthof sorted_array - 1) / 2)	; eax = middle
	mov ebx, 0					; ebx = start
	mov ecx, (lengthof sorted_array - 1)		; ecx = end

	.while ebx <= ecx
		.if edi == sorted_array[eax*4]
			mov esi, 1
			jmp _out_
		
		.elseif edi < sorted_array[eax*4]
			mov ecx, eax

		.elseif edi > sorted_array[eax*4]
			mov ebx, eax
			inc ebx

		.endif

		mov eax, ebx
		add eax, ecx
		mov edx, 0
		div _two_
	.endw

	_out_:
		
		.if esi == 1
			mov edx, offset found
		
		.else
			mov edx, offset not_found

		.endif

		call writestring

		call readchar

exit
main endp
end main
