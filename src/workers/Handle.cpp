/* XMRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2016-2017 XMRig       <support@xmrig.com>
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#include "workers/Handle.h"
#include "workers/OclThread.h"


Handle::Handle(int threadId, OclThread *thread, GpuContext *ctx, int threads, bool lite) :
    m_lite(lite),
    m_threadId(threadId),
    m_threads(threads),
    m_gpuThread(thread),
    m_ctx(ctx),
    m_worker(nullptr)
{
    thread->setThreadId(threadId);
	ctx->threadId = threadId;
}


void Handle::join()
{
    uv_thread_join(&m_thread);
}


void Handle::start(void (*callback) (void *))
{
    uv_thread_create(&m_thread, callback, this);
}
