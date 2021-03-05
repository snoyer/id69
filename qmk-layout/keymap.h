#include QMK_KEYBOARD_H

#define XX KC_NO
#define LAYOUT( \
    A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, Aa, Ab, Ac,     Ae, \
    B0, B1, B2, B3, B4, B5, B6, B7, B8, B9, Ba, Bb, Bc, Bd, Be, \
    C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, Ca, Cb, Cc, Cd, Ce, \
    D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, Da, Db,     Dd, De, \
    E0, E1, E2,     E4    ,     E7    , E9, Ea, Eb, Ec, Ed, Ee  \
) LAYOUT_ortho_5x15( \
    A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, Aa, Ab, Ac, XX, Ae, \
    B0, B1, B2, B3, B4, B5, B6, B7, B8, B9, Ba, Bb, Bc, Bd, Be, \
    C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, Ca, Cb, Cc, Cd, Ce, \
    D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, Da, Db, XX, Dd, De, \
    E0, E1, E2, XX, E4, XX, XX, E7, XX, E9, Ea, Eb, Ec, Ed, Ee  \
)



struct Longtimer {
    uint16_t ms;
    uint16_t s;
};

inline uint16_t longtimer_elapsed(struct Longtimer *timer) {
    const uint16_t e = timer_elapsed(timer->ms);
    if(e>1000) {
        timer->s += e/1000;
        timer->ms = timer_read(); // not 100% correct but good enough
    }
    return timer->s;
}

inline void longtimer_read(struct Longtimer *timer) {
    timer->ms = timer_read();
    timer->s = 0;
}


