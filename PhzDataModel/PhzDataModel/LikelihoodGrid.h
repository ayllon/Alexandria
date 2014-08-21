/** 
 * @file PhzDataModel/LikelihoodGrid.h
 * @date June 2, 2014
 * @author Nikolaos Apostolakos
 */

#ifndef PHZDATAMODEL_LIKELIHOODGRID_H
#define	PHZDATAMODEL_LIKELIHOODGRID_H

#include <vector>
#include "PhzDataModel/PhzModel.h"

namespace PhzDataModel {

typedef std::vector<double> LikelihoodCellManager;

typedef PhzGrid<LikelihoodCellManager> LikelihoodGrid;

}

#endif	/* PHZDATAMODEL_LIKELIHOODGRID_H */
