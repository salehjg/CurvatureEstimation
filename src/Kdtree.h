#ifndef KDTREE_INCLUDED
#define KDTREE_INCLUDED

#include <flann/flann.hpp>

template<typename Real>
class KDTree: public flann::Index<flann::L2<Real> >
{
#ifndef WIN32
	using flann::Index<flann::L2<Real> >::knnSearch;
	using flann::Index<flann::L2<Real> >::buildIndex;
	using flann::Index<flann::L2<Real> >::Index;
#endif
public:
	KDTree();
	void setInputPoints(Real* points, size_t npts);
	int KnnSearch(Real* queries, size_t nqrs,
		std::vector<std::vector<int> >& indices, 
		std::vector<std::vector<Real> >& dists, 
		const size_t knn) const;

};

#include "Kdtree.inl"

#endif