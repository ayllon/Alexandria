/** 
 * @file tests/src/AsciiWriterHelper_test.cpp
 * @date April 11, 2014
 * @author Nikolaos Apostolakos
 */

#include <boost/test/unit_test.hpp>
#include <strstream>
#include "ElementsKernel/ElementsException.h"
#include "ChTable/ColumnInfo.h"
#include "ChTable/Row.h"
#include "ChTable/Table.h"
#include "src/lib/AsciiWriterHelper.h"

struct AsciiWriterHelper_Fixture {
  std::vector<ChTable::ColumnInfo::info_type> info_list {
      ChTable::ColumnInfo::info_type("Boolean", typeid(bool)),
      ChTable::ColumnInfo::info_type("ThisIsAVeryLongColumnName", typeid(std::string)),
      ChTable::ColumnInfo::info_type("Integer", typeid(int32_t)),
      ChTable::ColumnInfo::info_type("D", typeid(double)),
      ChTable::ColumnInfo::info_type("F", typeid(float))
  };
  std::shared_ptr<ChTable::ColumnInfo> column_info {new ChTable::ColumnInfo {info_list}};
  std::vector<ChTable::Row::cell_type> values0 {true, std::string{"Two-1"}, 1, 4.1, 0.f};
  ChTable::Row row0 {values0, column_info};
  std::vector<ChTable::Row::cell_type> values1 {false, std::string{"Two-2"}, 1234567890, 42e-16, 0.f};
  ChTable::Row row1 {values1, column_info};
  std::vector<ChTable::Row::cell_type> values2 {true, std::string{"Two-3"}, 234, 4.3, 0.f};
  ChTable::Row row2 {values2, column_info};
  std::vector<ChTable::Row> row_list {row0, row1, row2};
  ChTable::Table table {row_list};
};

//-----------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE (AsciiWriterHelper_test)

//-----------------------------------------------------------------------------
// Test the typeToKeyword
//-----------------------------------------------------------------------------

BOOST_FIXTURE_TEST_CASE(typeToKeyword, AsciiWriterHelper_Fixture) {
  
  // When
  std::string bool_key = ChTable::typeToKeyword(typeid(bool));
  std::string int32_key = ChTable::typeToKeyword(typeid(int32_t));
  std::string int64_key = ChTable::typeToKeyword(typeid(int64_t));
  std::string float_key = ChTable::typeToKeyword(typeid(float));
  std::string double_key = ChTable::typeToKeyword(typeid(double));
  std::string string_key = ChTable::typeToKeyword(typeid(std::string));
  
  // Then
  BOOST_CHECK_EQUAL(bool_key, "bool");
  BOOST_CHECK_EQUAL(int32_key, "int");
  BOOST_CHECK_EQUAL(int64_key, "long");
  BOOST_CHECK_EQUAL(float_key, "float");
  BOOST_CHECK_EQUAL(double_key, "double");
  BOOST_CHECK_EQUAL(string_key, "string");
  
}

//-----------------------------------------------------------------------------
// Test the calculateColumnLengths
//-----------------------------------------------------------------------------

BOOST_FIXTURE_TEST_CASE(calculateColumnLengths, AsciiWriterHelper_Fixture) {
  
  // When
  auto sizes = ChTable::calculateColumnLengths(table);
  
  // Then
  BOOST_CHECK_EQUAL(sizes[0], 8);
  BOOST_CHECK_EQUAL(sizes[1], 26);
  BOOST_CHECK_EQUAL(sizes[2], 11);
  BOOST_CHECK_EQUAL(sizes[3], 8);
  BOOST_CHECK_EQUAL(sizes[4], 6);
  
}

//-----------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE_END ()