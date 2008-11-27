
//         Copyright E�in O'Callaghan 2006 - 2008.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#define HALITE_VERSION					0, 3, 1, 634
#define HALITE_VERSION_STRING			"v 0.3.1.6 dev 634"
#define	HALITE_FINGERPRINT				"HL", 0, 3, 1, 6

#ifndef HAL_NA
#define HAL_NA 40013
#endif

#define HAL_TORRENT_EXT_BEGIN 				41000
#define LBT_EVENT_TORRENT_FINISHED			HAL_TORRENT_EXT_BEGIN + 1
#define HAL_PEER_BAN_ALERT					HAL_TORRENT_EXT_BEGIN + 2
#define HAL_HASH_FAIL_ALERT					HAL_TORRENT_EXT_BEGIN + 3
#define HAL_URL_SEED_ALERT					HAL_TORRENT_EXT_BEGIN + 5
#define HAL_TRACKER_WARNING_ALERT			HAL_TORRENT_EXT_BEGIN + 4
#define HAL_TRACKER_ANNOUNCE_ALERT			HAL_TORRENT_EXT_BEGIN + 6
#define HAL_TRACKER_ALERT					HAL_TORRENT_EXT_BEGIN + 7
#define HAL_TRACKER_REPLY_ALERT				HAL_TORRENT_EXT_BEGIN + 8
#define LBT_EVENT_TORRENT_PAUSED			HAL_TORRENT_EXT_BEGIN + 9
#define HAL_FAST_RESUME_ALERT				HAL_TORRENT_EXT_BEGIN + 10
#define HAL_PIECE_FINISHED_ALERT			HAL_TORRENT_EXT_BEGIN + 11
#define HAL_BLOCK_FINISHED_ALERT			HAL_TORRENT_EXT_BEGIN + 12
#define HAL_BLOCK_DOWNLOADING_ALERT			HAL_TORRENT_EXT_BEGIN + 13
#define HAL_LISTEN_SUCCEEDED_ALERT			HAL_TORRENT_EXT_BEGIN + 14
#define HAL_LISTEN_FAILED_ALERT				HAL_TORRENT_EXT_BEGIN + 15
#define HAL_IPFILTER_ALERT					HAL_TORRENT_EXT_BEGIN + 16
#define HAL_INCORRECT_ENCODING_LEVEL		HAL_TORRENT_EXT_BEGIN + 17
#define HAL_INCORRECT_CONNECT_POLICY    	HAL_TORRENT_EXT_BEGIN + 18
#define HAL_PEER_ALERT						HAL_TORRENT_EXT_BEGIN + 19
#define HAL_LISTEN_V6_FAILED_ALERT			HAL_TORRENT_EXT_BEGIN + 20
#define HAL_TORRENT_LOAD_FILTERS			HAL_TORRENT_EXT_BEGIN + 21
#define HAL_EXTERNAL_IP_ALERT				HAL_TORRENT_EXT_BEGIN + 22
#define HAL_PORTMAP_ERROR_ALERT				HAL_TORRENT_EXT_BEGIN + 23
#define HAL_PORTMAP_ALERT					HAL_TORRENT_EXT_BEGIN + 24
#define HAL_PORTMAP_TYPE_PMP				HAL_TORRENT_EXT_BEGIN + 25			
#define HAL_PORTMAP_TYPE_UPNP				HAL_TORRENT_EXT_BEGIN + 26
#define HAL_FILE_ERROR_ALERT				HAL_TORRENT_EXT_BEGIN + 27
#define HAL_DHT_REPLY_ALERT					HAL_TORRENT_EXT_BEGIN + 28
#define HAL_WRITE_RESUME_ALERT				HAL_TORRENT_EXT_BEGIN + 29

#define HAL_TORRENT_INT_BEGIN 				42000
#define HAL_PEER_INTERESTING            	HAL_TORRENT_INT_BEGIN + 1
#define HAL_PEER_CHOKED             		HAL_TORRENT_INT_BEGIN + 2
#define HAL_PEER_REMOTE_INTERESTING			HAL_TORRENT_INT_BEGIN + 3
#define HAL_PEER_REMOTE_CHOKED				HAL_TORRENT_INT_BEGIN + 4
#define HAL_PEER_SUPPORT_EXTENSIONS			HAL_TORRENT_INT_BEGIN + 5
#define HAL_PEER_LOCAL_CONNECTION			HAL_TORRENT_INT_BEGIN + 6
#define HAL_PEER_HANDSHAKE					HAL_TORRENT_INT_BEGIN + 7
#define HAL_PEER_CONNECTING					HAL_TORRENT_INT_BEGIN + 8
#define HAL_PEER_QUEUED						HAL_TORRENT_INT_BEGIN + 9
#define HAL_PEER_RC4_ENCRYPTED				HAL_TORRENT_INT_BEGIN + 10
#define HAL_PEER_PLAINTEXT_ENCRYPTED		HAL_TORRENT_INT_BEGIN + 11
#define HAL_TORRENT_QUEUED_CHECKING			HAL_TORRENT_INT_BEGIN + 12
#define HAL_TORRENT_CHECKING_FILES			HAL_TORRENT_INT_BEGIN + 13
#define HAL_TORRENT_CONNECTING				HAL_TORRENT_INT_BEGIN + 14
#define HAL_TORRENT_DOWNLOADING				HAL_TORRENT_INT_BEGIN + 15
#define HAL_TORRENT_FINISHED				HAL_TORRENT_INT_BEGIN + 16
#define HAL_TORRENT_SEEDING					HAL_TORRENT_INT_BEGIN + 17
#define HAL_TORRENT_ALLOCATING				HAL_TORRENT_INT_BEGIN + 18
#define HAL_TORRENT_QUEUED					HAL_TORRENT_INT_BEGIN + 19
#define HAL_TORRENT_STOPPED					HAL_TORRENT_INT_BEGIN + 20
#define HAL_TORRENT_PAUSED					HAL_TORRENT_INT_BEGIN + 21
#define HAL_TORRENT_STOPPING				HAL_TORRENT_INT_BEGIN + 22
#define HAL_TORRENT_PAUSING					HAL_TORRENT_INT_BEGIN + 23
#define HAL_TORRENT_METADATA            	HAL_TORRENT_INT_BEGIN + 24
#define HAL_NEWT_CREATING_TORRENT			HAL_TORRENT_INT_BEGIN + 25
#define HAL_NEWT_HASHING_PIECES            	HAL_TORRENT_INT_BEGIN + 26
#define HAL_TORRENT_IMPORT_FILTERS         	HAL_TORRENT_INT_BEGIN + 27
#define HAL_INT_NEWT_ADD_PEERS_WEB         	HAL_TORRENT_INT_BEGIN + 28
#define HAL_INT_NEWT_ADD_PEERS_DHT         	HAL_TORRENT_INT_BEGIN + 29
#define HAL_NEWT_CREATION_CANCELED         	HAL_TORRENT_INT_BEGIN + 30
