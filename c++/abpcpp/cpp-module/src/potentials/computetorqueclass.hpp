#ifndef __computetorqueclass_HPP__
#define __computetorqueclass_HPP__

/** @defgroup computeenergy Compute Vertex Energy
 *  @brief ComputeTorqueClass abstracts definitions
 *  @{
 */
#include <memory>
#include <iostream>

#include "../types/globaltypes.hpp"
#include "../system/systemclass.hpp"
/**
 * @class ComputeTorqueClass
 * @brief ComputeTorqueClass abstract class for compute different potentials, forces and torques
 */

class ComputeTorqueClass
{
public:
  /**
   * @brief ComputeTorqueClass constructor
   * @param SystemClass reference to the system
   */
  ComputeTorqueClass(SystemClass &system) : _system(system)
  {
    rcut = 0.0;
  }
  /**
     * @brief ComputeTorqueClass Destructor
     */
  virtual ~ComputeTorqueClass() {}
  /**
     * @brief compute energy for the actual configuration
     * @param void
     * @return void 
     */
  virtual void compute_energy(void){};
  /**
     * @brief compute force for the actual configuration
     * @param void
     * @return void 
     */
  virtual void compute(void){};
  /**
     * @brief Get the name object
     * @return std::string 
     */
  std::string get_name(void) { return name; }
  /**
     * @brief Get the type object
     * @return std::string 
     */
  std::string get_type(void) { return type; }
  /**
     * @brief Get the pair potential's cut off radius 
     * @return std::string 
   */
  real get_rcut(void) { return rcut; }
  /**
     * @brief Set property
    */
  virtual void set_defaults_property(void) = 0;
  virtual void set_property(const std::string &, const double &) { this->print_warning_calling("double "); };
  void print_warning_calling(const std::string &message) { std::cerr << "torque " << name << " cannot be called with " << message << "\n"; }
  void print_warning_property_name(const std::string &message) { std::cerr << "parameter " << message << " is not part of " << name << " potential \n"; }

protected:
  SystemClass &_system; //!< Reference to the system
  std::string name;     //!< Name declared for that potential
  std::string type;     //!< Potential type, active, torque, conservative, etc
  real rcut;            //!< maximum cut off radius for a given potential
};

typedef std::shared_ptr<ComputeTorqueClass> ComputeTorqueClass_ptr;

#endif

/** @} */
