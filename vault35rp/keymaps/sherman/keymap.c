/* Copyright 2023 projectcain
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Tap dance
/*
 * enum tap_dances {
 *     TD_QUOTE,
 * };
 *
 * tap_dance_action_t tap_dance_actions[] = {
 *     [TD_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_QUOT),
 * };
 *
 */

enum layer_names {
    _BASE,
    _NAV,
    _PUN,
    _NUM,
    _FUN,
    _KEY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_wkl(
        KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,      KC_Y,            KC_U,          KC_I,          KC_O,          KC_P,    KC_QUOT,
        LGUI_T(KC_A),  LALT_T(KC_S),  LSFT_T(KC_D),  LCTL_T(KC_F),  KC_G,      KC_H,            RCTL_T(KC_J),  RSFT_T(KC_K),  RALT_T(KC_L),  RGUI_T(KC_SCLN),
        KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,      KC_N,            KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,
        MO(_FUN),                     MO(_NAV),                     KC_SPC,    KC_BSPC,         MO(_PUN),                     MO(_NUM)
    ),
    [_NAV] = LAYOUT_wkl(
        KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,      KC_Y,            KC_U,          KC_I,          KC_O,          KC_P,    KC_TRNS,
        KC_LGUI,       KC_LALT,       KC_LSFT,       KC_LCTL,       KC_HOME,   KC_LEFT,         KC_DOWN,       KC_UP,         KC_RIGHT,      KC_END,
        KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,      KC_N,            KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,
        KC_TRNS,                      KC_TRNS,                      KC_TRNS,   KC_TRNS,                        KC_TRNS,                      KC_TRNS
    ),
    [_PUN] = LAYOUT_wkl(
        KC_EXLM,       KC_ASTR,       KC_HASH,       KC_MINS,       KC_PLUS,   KC_NO,           KC_AT,         KC_DOLLAR,     KC_PERC,       KC_CIRC, KC_TRNS,
        KC_PIPE,       KC_AMPR,       KC_LPRN,       KC_RPRN,       KC_DQUO,   KC_QUOT,         KC_LCTL,       KC_LSFT,       KC_LALT,       KC_LGUI,
        KC_TILD,       KC_DLR,        KC_LBRC,       KC_RBRC,       KC_GRAVE,  KC_LCBR,         KC_RCBR,       KC_BSLS,       KC_NO,         KC_NO,
        KC_TRNS,                      KC_TRNS,                      KC_TRNS,   KC_TRNS,                        KC_TRNS,                      KC_TRNS
    ),
    [_NUM] = LAYOUT_wkl(
        QK_BOOT,       KC_W,          KC_E,          KC_R,          KC_T,      KC_Y,            KC_U,          KC_I,          KC_O,          KC_P,    KC_TRNS,
        LGUI_T(KC_A),  LALT_T(KC_S),  LSFT_T(KC_D),  LCTL_T(KC_F),  KC_G,      KC_H,            RCTL_T(KC_J),  RSFT_T(KC_K),  RALT_T(KC_L),  RGUI_T(KC_QUOTE),
        KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,      KC_N,            KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,
        KC_TRNS,                      KC_TRNS,                      KC_TRNS,   KC_TRNS,                        KC_TRNS,                      KC_TRNS
    ),
    [_FUN] = LAYOUT_wkl(
        QK_BOOT,       EE_CLR,        KC_E,          KC_R,          KC_T,      KC_Y,            KC_U,          KC_I,          KC_O,          KC_P,    KC_TRNS,
        LGUI_T(KC_A),  LALT_T(KC_S),  LSFT_T(KC_D),  LCTL_T(KC_F),  KC_G,      KC_H,            RCTL_T(KC_J),  RSFT_T(KC_K),  RALT_T(KC_L),  RGUI_T(KC_QUOTE),
        KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,      KC_N,            KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,
        KC_TRNS,                      KC_TRNS,                      KC_TRNS,   KC_TRNS,                        KC_TRNS,                      KC_TRNS
    ),
    [_KEY] = LAYOUT_wkl(
        QK_BOOT,       EE_CLR,        KC_E,          KC_R,          KC_T,      KC_Y,            KC_U,          KC_I,          KC_O,          S(C(QK_MAKE)),  QK_MAKE,
        LGUI_T(KC_A),  LALT_T(KC_S),  LSFT_T(KC_D),  LCTL_T(KC_F),  KC_G,      UG_PREV,         UG_VALD,       UG_VALU,       UG_NEXT,       KC_TRNS,
        KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,      KC_N,            KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,
        KC_TRNS,                      KC_TRNS,                      UG_TOGG,   KC_TRNS,                  KC_TRNS,                      KC_TRNS
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_UP, KC_DOWN) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
};
#endif

enum combos {
    // My combos
    QW_ESC,
    MOFUN_MONUM_MOKEY,
    P_QUOT_RPRN,
    O_P_LPRN,
    M_COMM_LCBR,
    COMM_DOT_RCBR,
    AS_TAB,
    SPACE_BSPC
};

// My combos
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM fun_num_combo[] = {MO(_FUN), MO(_NUM), COMBO_END};
const uint16_t PROGMEM p_quot_combo[] = {KC_P, KC_QUOT, COMBO_END};
const uint16_t PROGMEM o_p_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM m_comm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM comm_dot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM as_combo[] = {LGUI_T(KC_A), LALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM space_bspc_combo[] = {KC_SPC, KC_BSPC, COMBO_END};

combo_t key_combos[] = {
    // My combos
    [QW_ESC] = COMBO(qw_combo, KC_ESC),
    [MOFUN_MONUM_MOKEY] = COMBO(fun_num_combo, MO(_KEY)),
    [P_QUOT_RPRN] = COMBO(p_quot_combo, KC_RPRN),
    [O_P_LPRN] = COMBO(o_p_combo, KC_LPRN),
    [M_COMM_LCBR] = COMBO(m_comm_combo, KC_LCBR),
    [COMM_DOT_RCBR] = COMBO(comm_dot_combo, KC_RCBR),
    [AS_TAB] = COMBO(as_combo, KC_TAB),
    [SPACE_BSPC] = COMBO(space_bspc_combo, KC_ENTER),
};

// Configs for keymap
// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case TD(TD_QUOTE):
//             return 165;
//         default:
//             return TAPPING_TERM;
//     };
// };

