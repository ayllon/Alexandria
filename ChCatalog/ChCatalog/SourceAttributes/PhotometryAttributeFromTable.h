/**
 * @file PhotometryAttributeHandler.h
 *
 * @date Apr 17, 2014
 * @author Pierre Dubath
 */

#ifndef PHOTOMETRYATTRIBUTEHANDLER_H_
#define PHOTOMETRYATTRIBUTEHANDLER_H_
#include <map>
#include <utility>
#include <string>
#include <memory>


#include "ChCatalog/AttributeFromTable.h"
#include "ChCatalog/Catalog.h"
#include "ChTable/Table.h"

namespace ChCatalog {

/**
 * @class PhotometryAttributeHandler
 * @brief Implementation of the AttributeHandler for a photometry attribute.
 * This class implements the createAttribute method that must be used to
 * create Photometry objects.
 *
 */
class PhotometryAttributeFromTable : public AttributeFromTable {
public:
  /**
   * @brief Create a PhotometryAttributeHandler object
   *
   * @details Create a PhotometryAttributeHandler object, setting up the rule for building
   * PhotometryAttribute from a Table row. The filter_name_mapping provides the correspondence
   * between the filterName (string) and the names used for the Table columns. These names (of
   * the flux and the error columns) are searched in the columnInfo of the Table and a new
   * mapping between the filterName and the indices of the flux and of the error columns is built.
   * The user must provide this mapping between the filterName (which are then used throughout the
   * processing) and the column names which comes from the input photometric (ASCII or FITS) catalog.
   *
   * @param columnInfo
   *    describes the columns of the Table providing in particular the require column names
   *
   * @param filter_name_mapping
   *    supplies the mapping between the filter name (std::string) and the Table column names,
   *    both for the flux and for the error columns
   *
   * @exception
   *  An exception is thrown if the names provided in the mapping are not present in the columnInfo.
   */
  PhotometryAttributeFromTable(std::shared_ptr<ChTable::ColumnInfo> column_info_ptr,
      const std::map<std::string, std::pair<std::string, std::string>> filter_name_mapping);

  virtual ~PhotometryAttributeFromTable();

  /**
   * @brief Create a photometricAttribute from a Table row
   * @details Create a photometricAttribute from a Table row using the mapping included in this object
   * @param A ChTable row
   * @return A unique pointer to a (Photometry) Attribute
   */
  std::unique_ptr<Attribute> createAttribute(const ChTable::Row& row) override;

  /**
   * @brief Getting the private m_filter_index_mapping for testing purpose only
   * @return The filter_index_mapping
   */
  const std::map<std::string, std::pair<size_t, size_t> >& getFilterIndexMapping() const {
    return m_filter_index_mapping;
  }

private:
  /*
   * Map the correspondence between the filterName and the indexes used in the Table columns
   */
  std::map<std::string, std::pair<size_t, size_t> > m_filter_index_mapping;

  /*
   * Pointer to the shared filter name vector
   */
  std::shared_ptr<std::vector<std::string>> m_filter_name_vector_ptr;

};

} // namespace ChCatalog 

#endif // PHOTOMETRYATTRIBUTEHANDLER_H_ 
