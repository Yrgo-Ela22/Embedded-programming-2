/********************************************************************************
 * @brief Contains structure for storing electrical values.
 ********************************************************************************/
#pragma once

#include <stdlib.h>

/********************************************************************************
 * @brief If the code is compiled as C++, the content is compiled as C code.
 ********************************************************************************/
#ifdef __cplusplus 
extern "C" {
#endif 

/********************************************************************************
 * @brief Predeclaring structure for storing electrical values (the members are
 *        private, hence the struct is not declared here).
 ********************************************************************************/
struct electrical;

/********************************************************************************
 * @brief Creates a new heap allocated structure storing electrical quantities.
 * 
 * @param voltage_v
 *        The voltage measured in V.
 * @param current_ma
 *        The current measured in mA.
 * @return
 *        A reference to the new structure.
 ********************************************************************************/
struct electrical* electrical_new(const double voltage_v, const double current_ma);

/********************************************************************************
 * @brief Deletes heap allocated electrical structure and sets the corresponding
 *        pointer to null.
 * 
 * @param self
 *        Address to the electrical structure pointer.
 ********************************************************************************/
void electrical_delete(struct electrical** self);

/********************************************************************************
 * @brief Provides the voltage stored by referenced electrical structure.
 * 
 * @param self
 *        Reference to the electrical structure.
 * @return
 *        The voltage in V.
 ********************************************************************************/
double electrical_voltage_v(const struct electrical* self);

/********************************************************************************
 * @brief Provides the current stored by referenced electrical structure.
 * 
 * @param self
 *        Reference to the electrical structure.
 * @return
 *        The current in mA.
 ********************************************************************************/
double electrical_current_ma(const struct electrical* self);

/********************************************************************************
 * @brief Provides the resistance stored by referenced electrical structure.
 * 
 * @param self
 *        Reference to the electrical structure.
 * @return
 *        The current in kOhm.
 ********************************************************************************/
double electrical_resistance_kohm(const struct electrical* self);

/********************************************************************************
 * @brief Provides the power stored by referenced electrical structure.
 * 
 * @param self
 *        Reference to the electrical structure.
 * @return
 *        The power of mW.
 ********************************************************************************/
double electrical_power_mw(const struct electrical* self);

#ifdef __cplusplus
} /* extern "C" */
#endif





