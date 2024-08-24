build:
	qmk compile -kb projectcain/vault35rp -km sherman
lint:
	qmk lint -kb projectcain/vault35rp -km sherman
build-yaml:
	qmk c2json -km sherman -kb projectcain/vault35rp | keymap parse -c 4 -q -
build-svg:
	mkdir -p ../../output
	qmk c2json -km sherman -kb projectcain/vault35rp | \
		keymap -c ../../../keymap-drawer-config.yaml parse -c 4 -l BASE NAV SYM NUM FUN KEY -q - | \
		cat - combo-keymap.yaml | \
		../../../modifiers-to-glyphs.sed - > \
		../../output/keymap.yaml 
	keymap -c ../../../keymap-drawer-config.yaml draw ../../output/keymap.yaml -j ../../info.json -l LAYOUT_wkl > \
    	../../output/keyboard.svg
clean:
	rm -rf ../../output
