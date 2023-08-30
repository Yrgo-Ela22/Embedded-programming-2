#include <electrical.h>

struct electrical {
    double voltage_v; 
    double current_ma;
    double resistance_kohm;
    double power_mw;
};


struct electrical* electrical_new(const double voltage_v, const double current_ma) {
    struct electrical* self = (struct electrical*)malloc(sizeof(struct electrical));
    if (!self) return 0;
    self->voltage_v = voltage_v;
    self->current_ma = current_ma;
    self->resistance_kohm = current_ma != 0 ? voltage_v / current_ma : 0;
    self->power_mw = voltage_v * current_ma;
    return self;
}

void electrical_delete(struct electrical** self) {
    free(*self);
    *self = 0;
}

double electrical_voltage_v(const struct electrical* self) {
    return self->voltage_v;
}

double electrical_current_ma(const struct electrical* self) {
    return self->current_ma;
}

double electrical_resistance_kohm(const struct electrical* self) {
    return self->resistance_kohm;
}

double electrical_power_mw(const struct electrical* self) {
    return self->power_mw;
}

