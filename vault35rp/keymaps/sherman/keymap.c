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
#include "emails.h"

enum layer_names {
    _BASE,
    _NAV,
    _PUN,
    _NUM,
    _FUN,
    _KEY
};

/* 
 * // Tap dance
 * enum tap_dances {
 *     TD_NUM_FN,
 * };
 * 
 * void td_num_fn_finished(tap_dance_state_t *state, void *user_data) {
 *     if (state->count >= 2 && state->pressed) {
 *         layer_on(_FUN);
 *         return;
 *     }
 *     if (state->pressed) {
 *         layer_on(_NUM);
 *     }
 * }
 * 
 * 
 * void td_num_fn_reset(tap_dance_state_t *state, void *user_data) {
 *     if (state->count >= 2) {
 *         layer_off(_FUN);
 *         return;
 *     }
 *     layer_off(_NUM);
 * }
 * 
 * tap_dance_action_t tap_dance_actions[] = {
 *     [TD_NUM_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_fn_finished, td_num_fn_reset),
 * };
 */

// Custom Keycodes
enum custom_keycodes {
    SS_QAZ_PASTA = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_QAZ_PASTA:
            if (record->event.pressed) {
                SEND_STRING_DELAY(
                    "You guys always kill me because it's like "
                    "you come up with a funny idea for a keyboard meme "
                    "product and then someone spends actual effort "
                    "mocking it up or making a CAD model and then someone "
                    "decides to actually make it and you spend real "
                    "money on it because nobody had the sense to just " 
                    "say \"this is actually stupid\" somewhere along "
                    "the way.",
                    1
                );
            }
            break;
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_wkl(
        KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,      KC_Y,            KC_U,          KC_I,          KC_O,          KC_P,    KC_QUOT,
        LGUI_T(KC_A),  LALT_T(KC_S),  LSFT_T(KC_D),  LCTL_T(KC_F),  KC_G,      KC_H,            RCTL_T(KC_J),  RSFT_T(KC_K),  RALT_T(KC_L),  RGUI_T(KC_SCLN),
        KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,      KC_N,            KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,
        MO(_NAV),                     MO(_NUM),                     KC_SPC,    KC_BSPC,                        MO(_PUN),                     MO(_FUN)
    ),
    [_NAV] = LAYOUT_wkl(
        KC_NO,         KC_NO,         KC_NO,         KC_NO,         KC_NO,     KC_NO,           KC_NO,         KC_PGUP,       KC_PSCR,       KC_INS,  KC_DEL,
        KC_LGUI,       KC_LALT,       KC_LSFT,       KC_LCTL,       KC_HOME,   KC_LEFT,         KC_DOWN,       KC_UP,         KC_RIGHT,      KC_END,
        KC_NO,         KC_NO,         KC_NO,         KC_NO,         KC_NO,     KC_NO,           KC_PGDN,       KC_NO,         KC_NO,         KC_NO,
        KC_TRNS,                      KC_TRNS,                      KC_TRNS,   KC_TRNS,                        KC_TRNS,                      KC_TRNS
    ),
    [_PUN] = LAYOUT_wkl(
        KC_EXLM,       KC_AT,         KC_HASH,       KC_AMPR,       KC_ASTR,   KC_NO,           KC_NO,         KC_NO,         KC_NO,         KC_NO,   KC_TRNS,
        KC_DLR,        KC_PERC,       KC_MINS,       KC_EQL,        KC_PLUS,   KC_CIRC,         KC_LCTL,       KC_LSFT,       KC_LALT,       KC_LGUI,
        KC_BSLS,       KC_GRV,        KC_TILD,       KC_PIPE,       KC_NO,     KC_NO,           KC_NO,         KC_NO,         KC_NO,         KC_SLSH,
        KC_TRNS,                      KC_TRNS,                      KC_TRNS,   KC_TRNS,                        KC_TRNS,                      KC_TRNS
    ),
    [_NUM] = LAYOUT_wkl(
        KC_MINS,       KC_7,          KC_8,          KC_9,          KC_PLUS,   KC_NO,           KC_NO,         KC_NO,         KC_NO,         KC_NO,   KC_TRNS,
        LGUI_T(KC_0),  LALT_T(KC_1),  LSFT_T(KC_2),  LCTL_T(KC_3),  KC_4,      KC_5,            RCTL_T(KC_6),  RSFT_T(KC_7),  RALT_T(KC_8),  RGUI_T(KC_9),
        KC_ASTR,       KC_4,          KC_5,          KC_6,          KC_EQL,    KC_NO,           KC_NO,         KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_TRNS,                      KC_TRNS,                      KC_TRNS,   KC_TRNS,                        QK_LEAD,                      KC_TRNS
    ),
    [_FUN] = LAYOUT_wkl(
        KC_NO,         KC_NO,         KC_NO,         KC_NO,         KC_F11,    KC_F12,          KC_NO,         KC_NO,         KC_NO,         KC_NO,   KC_NO,
        LGUI_T(KC_F1), LALT_T(KC_F2), LSFT_T(KC_F3), LCTL_T(KC_F4), KC_F5,     KC_F6,           LCTL_T(KC_F7), LSFT_T(KC_F8), LALT_T(KC_F9), LGUI_T(KC_F10),
        KC_NO,         KC_NO,         KC_NO,         KC_NO,         KC_NO,     KC_NO,           KC_NO,         KC_NO,         KC_NO,         KC_NO,
        KC_TRNS,                      KC_TRNS,                      KC_TRNS,   KC_TRNS,                        KC_TRNS,                      KC_TRNS
    ),
    [_KEY] = LAYOUT_wkl(
        QK_BOOT,       KC_MUTE,       KC_MPLY,       KC_NO,         KC_NO,     KC_NO,           KC_NO,         KC_BRIU,       KC_NO,         KC_PWR,  KC_SLEP,
        KC_MPRV,       KC_VOLD,       KC_VOLU,       KC_MNXT,       KC_NO,     UG_PREV,         UG_VALD,       UG_VALU,       UG_NEXT,       KC_NO,
        KC_NO,         SS_QAZ_PASTA,  EE_CLR,        KC_NO,         KC_NO,     KC_NO,           KC_BRID,       KC_NO,         KC_NO,         KC_NO,
        KC_TRNS,                      KC_TRNS,                      UG_TOGG,   KC_TRNS,                        KC_TRNS,                      KC_TRNS
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_UP, KC_DOWN) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

// My combos
enum combos {
    QW_ESC,
    MOFUN_MONUM_MOKEY,
    P_QUOT_RPRN,
    O_P_LPRN,
    M_COMM_LCBR,
    COMM_DOT_RCBR,
    AS_TAB,
    SPACE_BSPC,
    QAZ_PASTA,
    Z_C_COPY,
    Z_X_CUT,
    Z_V_PASTE,
    NUM_PUN_LEADER
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM fun_num_combo[] = {MO(_NAV), MO(_FUN), COMBO_END};
const uint16_t PROGMEM p_quot_combo[] = {KC_P, KC_QUOT, COMBO_END};
const uint16_t PROGMEM o_p_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM m_comm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM comm_dot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM as_combo[] = {LGUI_T(KC_A), LALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM space_bspc_combo[] = {KC_SPC, KC_BSPC, COMBO_END};
const uint16_t PROGMEM qaz_pasta_combo[] = {KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM z_c_combo[] = {KC_Z, KC_C, COMBO_END};
const uint16_t PROGMEM z_x_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM z_v_combo[] = {KC_Z, KC_V, COMBO_END};
const uint16_t PROGMEM leader_combo[] = {MO(_NUM), MO(_PUN), COMBO_END};

combo_t key_combos[] = {
    [QW_ESC] = COMBO(qw_combo, KC_ESC),
    [MOFUN_MONUM_MOKEY] = COMBO(fun_num_combo, MO(_KEY)),
    [P_QUOT_RPRN] = COMBO(p_quot_combo, KC_RPRN),
    [O_P_LPRN] = COMBO(o_p_combo, KC_LPRN),
    [M_COMM_LCBR] = COMBO(m_comm_combo, KC_LBRC),
    [COMM_DOT_RCBR] = COMBO(comm_dot_combo, KC_RBRC),
    [AS_TAB] = COMBO(as_combo, KC_TAB),
    [SPACE_BSPC] = COMBO(space_bspc_combo, KC_ENTER),
    [QAZ_PASTA] = COMBO(qaz_pasta_combo, SS_QAZ_PASTA),
    [Z_C_COPY] = COMBO(z_c_combo, C(KC_C)),
    [Z_X_CUT] = COMBO(z_x_combo, C(KC_X)),
    [Z_V_PASTE] = COMBO(z_v_combo, C(KC_V)),
    [NUM_PUN_LEADER] = COMBO(leader_combo, QK_LEAD),
};


bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case SS_QAZ_PASTA:
            if (!layer_state_is(_KEY)) {
                return false;
            }
            break;
    }
    return true;
}

// Tap term timings
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Pinky keys
        case LGUI_T(KC_A):
        case LALT_T(KC_S):
        case RALT_T(KC_L):
        case RGUI_T(KC_SCLN):
        case LGUI_T(KC_0):
        case LALT_T(KC_1):
        case RALT_T(KC_8):
        case RGUI_T(KC_9):
            return 170;
        // All other keys
        default:
            return TAPPING_TERM;
    };
};


#ifdef LEADER_ENABLE
void vim_write(void) {
    SEND_STRING(SS_TAP(X_ESC) ":w" SS_TAP(X_ENT));
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_W)) {
        vim_write();
    } else if (leader_sequence_one_key(KC_E)) {
        SEND_STRING_DELAY(PERSONAL_EMAIL, 1);
    } else if (leader_sequence_three_keys(KC_W, KC_R, KC_K)) {
        SEND_STRING_DELAY(WORK_EMAIL, 1);
    } else if (leader_sequence_three_keys(KC_U, KC_N, KC_I)) {
        SEND_STRING_DELAY(UNI_EMAIL, 1);
    } else if (leader_sequence_two_keys(KC_P, KC_A)) {
        SEND_STRING_DELAY("()", 1);
    } else if (leader_sequence_two_keys(KC_P, KC_I)) {
        SEND_STRING_DELAY("()" SS_TAP(X_LEFT), 1);
    } else if (leader_sequence_two_keys(KC_B, KC_A)) {
        SEND_STRING_DELAY("{}", 1);
    } else if (leader_sequence_two_keys(KC_B, KC_I)) {
        SEND_STRING_DELAY("{}" SS_TAP(X_LEFT), 1);
    } else if (leader_sequence_three_keys(KC_B, KC_S, KC_A)) {
        SEND_STRING_DELAY("[]", 1);
    } else if (leader_sequence_three_keys(KC_B, KC_S, KC_I)) {
        SEND_STRING_DELAY("[]" SS_TAP(X_LEFT), 1);
    }
}
#endif

