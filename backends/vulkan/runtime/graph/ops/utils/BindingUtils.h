/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <executorch/backends/vulkan/runtime/graph/ComputeGraph.h>

namespace vkcompute {

//
// For objects in the graph
//

void bind_tensor_to_descriptor_set(
    api::vTensor& tensor,
    api::PipelineBarrier& pipeline_barrier,
    const api::MemoryAccessType accessType,
    api::DescriptorSet& descriptor_set,
    const uint32_t idx);

uint32_t bind_values_to_descriptor_set(
    ComputeGraph* graph,
    const std::vector<ArgGroup>& args,
    api::PipelineBarrier& pipeline_barrier,
    api::DescriptorSet& descriptor_set,
    const uint32_t base_idx);

//
// For objects NOT in the graph
//

uint32_t bind_params_to_descriptor_set(
    const api::ParamsBindList& params,
    api::DescriptorSet& descriptor_set,
    const uint32_t base_idx);

void bind_staging_to_descriptor_set(
    api::StorageBuffer& staging,
    api::DescriptorSet& descriptor_set,
    const uint32_t idx);

} // namespace vkcompute
