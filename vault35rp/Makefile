build:
	qmk compile -kb projectcain/vault35rp -km sherman
lint:
	qmk lint -kb projectcain/vault35rp -km sherman
build-image:
	mkdir -p output
	qmk c2json -km sherman -kb projectcain/vault35rp | \
		keymap parse -c 4 -q - |                       \
		keymap draw - -j info.json -l LAYOUT_wkl       \
		> ./output/keyboard.svg
clean:
	rm -rf output
