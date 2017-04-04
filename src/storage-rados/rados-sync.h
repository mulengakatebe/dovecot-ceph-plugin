#ifndef RADOS_SYNC_H
#define RADOS_SYNC_H

struct mailbox;

struct rados_sync_context {
	struct rados_mailbox *mbox;
        struct mail_index_sync_ctx *index_sync_ctx;
	struct mail_index_view *sync_view;
	struct mail_index_transaction *trans;

	string_t *path;
	size_t path_dir_prefix_len;
	uint32_t uid_validity;
};

int rados_sync_begin(struct rados_mailbox *mbox,
		     struct rados_sync_context **ctx_r, bool force);
int rados_sync_finish(struct rados_sync_context **ctx, bool success);

struct mailbox_sync_context *
rados_storage_sync_init(struct mailbox *box, enum mailbox_sync_flags flags);

#endif