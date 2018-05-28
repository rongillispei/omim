#include "track_analyzing/track.hpp"
#include "track_analyzing/track_analyzer/utils.hpp"

#include "routing_common/num_mwm_id.hpp"

#include "storage/storage.hpp"

#include "base/logging.hpp"

#include <fstream>
#include <memory>
#include <string>

namespace track_analyzing
{
using namespace routing;
using namespace std;

void CmdUnmatchedTracks(string const & logFile, string const & trackFileCsv)
{
  LOG(LINFO, ("Saving unmatched tracks", logFile));
  shared_ptr<NumMwmIds> numMwmIds;
  storage::Storage storage;
  MwmToTracks mwmToTracks;
  ParseTracks(logFile, numMwmIds, storage, mwmToTracks);

  ofstream ofs(trackFileCsv, std::ofstream::out);
  for (auto const & kv : mwmToTracks)
  {
    for (auto const & idTrack : kv.second)
    {
      ofs << numMwmIds->GetFile(kv.first).GetName() << ", " << idTrack.first;
      for (auto const & pnt : idTrack.second)
        ofs << ", " << pnt.m_latLon.lat << ", " << pnt.m_latLon.lon << ", " << pnt.m_timestamp;
      ofs << "\n";
    }
  }
}
}  // namespace track_analyzing
