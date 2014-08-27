/**
 * @file tests/src/TableFixture.h
 *
 * @date May 16, 2014
 * @author Pierre Dubath
 */

#ifndef TABLEFIXTURE_H_
#define TABLEFIXTURE_H_

#include <memory>
#include <vector>
#include <utility>
//#include "SourceCatalog/Source.h"
//#include "SourceCatalog/SourceAttributes/Photometry.h"
//#include "SourceCatalog/SourceAttributes/Coordinates.h"
//#include "SourceCatalog/SourceAttributes/SpectroscopicRedshift.h"
#include "Table/Row.h"
#include "Table/Table.h"
#include "Table/ColumnInfo.h"

using namespace Euclid::SourceCatalog;
using namespace std;

struct TableFixture {

  double tolerance = 1e-12;

  string source_id_name = "Test_source_id";
  string spec_z_val_col_name = "SpecZval";
  string spec_z_err_col_name = "SpecZerr";


  // A test table with two flux columns and two rows
  const vector<Euclid::Table::ColumnInfo::info_type> info_list {
    Euclid::Table::ColumnInfo::info_type(source_id_name, typeid(int64_t)),
    Euclid::Table::ColumnInfo::info_type("Boolean", typeid(bool)),
    Euclid::Table::ColumnInfo::info_type("Integer", typeid(int32_t)),
    Euclid::Table::ColumnInfo::info_type("Long", typeid(int64_t)),
    Euclid::Table::ColumnInfo::info_type("Float", typeid(float)),
    Euclid::Table::ColumnInfo::info_type("Double_flux1", typeid(double)),
    Euclid::Table::ColumnInfo::info_type("Double_flux2", typeid(double)),
    Euclid::Table::ColumnInfo::info_type("Double_error1", typeid(double)),
    Euclid::Table::ColumnInfo::info_type("Double_error2", typeid(double)),
    Euclid::Table::ColumnInfo::info_type("String", typeid(string)),
    Euclid::Table::ColumnInfo::info_type(spec_z_val_col_name, typeid(double)),
    Euclid::Table::ColumnInfo::info_type(spec_z_err_col_name, typeid(double))

  };
  const shared_ptr<Euclid::Table::ColumnInfo> column_info_ptr {
      new Euclid::Table::ColumnInfo { info_list } };

  int64_t source_id_1 { 756330785 };
  int64_t source_id_2 { 127548910 };

  double flux1_row1 = 1.12345e-12;
  double flux2_row1 = 1.12345e-1;
  double error1_row1 = 1.12345e-18;
  double error2_row1 = 1.1e-2;

  double spec_z_val_row0 = 0.234657;
  double spec_z_err_row0 = 0.089757;
  double spec_z_val_row1 = 0.1296457;
  double spec_z_err_row1 = 0.003647;

  const vector<Euclid::Table::Row::cell_type> values0 { source_id_1, true, 1,
      int64_t { 123 }, 0.F, 0., 0., 0., 0., string { "first" }, spec_z_val_row0,
      spec_z_err_row0 };
  const Euclid::Table::Row row0 { values0, column_info_ptr };
  const vector<Euclid::Table::Row::cell_type> values1 { source_id_2, false, 12345,
      int64_t { 123456789 }, 2.3e-2F, flux1_row1, flux2_row1, error1_row1,
      error2_row1, string { "second" }, spec_z_val_row1, spec_z_err_row1 };
  const Euclid::Table::Row row1 { values1, column_info_ptr };
  const vector<Euclid::Table::Row> row_list { row0, row1 };
  const Euclid::Table::Table table { row_list };

  // Two filter names
  const string v_filter_name { "TestGroup/VtestName" };
  const string r_filter_name { "TestGroup/RtestName" };

  // the mapping variable
  vector<pair<string, pair<string, string>>> filter_name_mapping;

  TableFixture() {
    // This is how the mapping must be defined
    filter_name_mapping.push_back(make_pair(v_filter_name,make_pair<string, string>("Double_flux1","Double_error1")));
    filter_name_mapping.push_back(make_pair(r_filter_name,make_pair<string, string>("Double_flux2","Double_error2")));
  }
  ~TableFixture() {
    // teardown
  }

};

#endif // TABLEFIXTURE_H_ 
