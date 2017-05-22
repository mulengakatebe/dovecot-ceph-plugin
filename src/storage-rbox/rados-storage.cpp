/* Copyright (c) 2017 Tallence AG and the authors, see the included COPYING file */

#include <string>

#include <rados/librados.hpp>

#include "rados-storage.h"

using namespace librados;  // NOLINT

using std::string;

#define DICT_USERNAME_SEPARATOR '/'

RadosStorage::RadosStorage(librados::IoCtx *ctx, const string &username, const string &oid)
    : io_ctx(*ctx), username(username), oid(oid) {}

RadosStorage::~RadosStorage() { get_io_ctx().close(); }

void RadosStorage::generate_guid(guid_128_t guid) {
  guid_128_generate(guid);
}