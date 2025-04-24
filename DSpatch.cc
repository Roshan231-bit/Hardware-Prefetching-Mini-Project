   /* #include <algorithm>
    #include <array>
    #include <map>
    #include <iostream>
    #include "cache.h"  

    #include <unordered_map>
    #include <vector>

    using namespace std;

    // Define structures for Page Buffer (PB) and Signature Pattern Table (SPT)
    unordered_map<uint64_t, uint64_t> PB;
    unordered_map<uint64_t, pair<uint64_t, uint64_t>> SPT;

    // Function to initialize the prefetcher
    void CACHE::prefetcher_initialize() {
        // Initialize any necessary data structures
        PB.clear();
        SPT.clear();
    }

    // Main prefetching function
    uint32_t CACHE::prefetcher_cache_operate(uint64_t addr, uint64_t ip, uint8_t cache_hit, bool useful_prefetch, uint8_t type, uint32_t metadata_in) {
        // Record program access bit-patterns in Page Buffer (PB)
        uint64_t physical_page_accessed = addr >> LOG2_BLOCK_SIZE;
        PB[physical_page_accessed] |= (1 << (ip % 64));

        // Lookup Signature Pattern Table (SPT) with triggering PC
        auto it = SPT.find(ip);
        uint64_t CoP, AccP;
        if (it != SPT.end()) {
            CoP = it->second.first;
            AccP = it->second.second;
        } else {
            CoP = 0;
            AccP = 0;
        }

        // Determine which bit-pattern to use based on memory bandwidth utilization
        uint64_t prefetch_bit_pattern;
        if (memory_bandwidth_utilization) {
            prefetch_bit_pattern = AccP;
        } else {
            prefetch_bit_pattern = CoP;
        }

        // Generate prefetch requests based on the selected bit-pattern
        vector<uint64_t> prefetch_requests;
        generatePrefetchRequests(prefetch_bit_pattern, physical_page_accessed, prefetch_requests);

        // Issue prefetch requests to memory subsystem
        for (uint64_t addr : prefetch_requests) {
            uint64_t set = get_set(addr);
            uint32_t way = get_way(addr, set);
            prefetcher_cache_fill(addr, set, way, 1, metadata_in);
        }

        // Return any necessary metadata
        return 0; // Placeholder return value
    }

    // Function to handle cache fill requests from the prefetcher
    uint32_t CACHE::prefetcher_cache_fill(uint64_t addr, uint32_t set, uint32_way, uint8_t prefetch, uint32_t metadata_in) {
        // Handle cache fill requests from the prefetcher
        // Perform any necessary operations
        return 0; // Placeholder return value
    }

    // Function to perform prefetcher operations per cycle
    void CACHE::prefetcher_cycle_operate() {
        // Perform any necessary operations per cycle
    }

    // Function to finalize prefetcher statistics
    void CACHE::prefetcher_final_stats() {
        // Calculate and output prefetcher statistics
    }

    // Function to handle branch operations (if needed for prefetcher)
    void CACHE::prefetcher_branch_operate(uint64_t ip, uint8_t branch_type, uint64_t branch_target) {
        // Handle branch operations if needed for prefetcher
    }

    // Learning bit-patterns function
    void learnBitPatterns() {
        // Iterate over all entries in Page Buffer (PB)
        for (auto& entry : PB) {
            uint64_t physical_page_accessed = entry.first;
            uint64_t bit_pattern = entry.second;

            // Calculate CoP and AccP based on observed access patterns
            uint64_t CoP = calculateCoverageBiasedBitPattern(bit_pattern);
            uint64_t AccP = calculateAccuracyBiasedBitPattern(CoP, bit_pattern);

            // Store CoP and AccP in Signature Pattern Table (SPT) associated with PC
            SPT[physical_page_accessed] = make_pair(CoP, AccP);
        }
    }

    // Function to calculate CoP (coverage-biased bit-pattern)
    uint64_t calculateCoverageBiasedBitPattern(uint64_t bit_pattern) {
        // OR operation of recently observed spatial program access bit-patterns
        // up to a certain threshold
        // Add bits to the learnt bit-pattern to increase coverage
        return bit_pattern;
    }

    // Function to calculate AccP (accuracy-biased bit-pattern)
    uint64_t calculateAccuracyBiasedBitPattern(uint64_t CoP, uint64_t bit_pattern) {
        // AND operation of the coverage-biased bit-pattern (CoP) and the currently
        // observed program access bit-pattern to the physical page
        // Reduce set bits to maximize accuracy
        return CoP & bit_pattern;
    }

    // Function to generate prefetch requests based on a given bit-pattern
    void generatePrefetchRequests(uint64_t bit_pattern, uint64_t physical_page_accessed, vector<uint64_t>& prefetch_requests) {
        // Use the bit-pattern to generate prefetch candidates
        // Generate prefetch requests based on the bit-pattern
        // For illustration, let's just prefetch the next 4 lines
        for (int i = 1; i <= 4; i++) {
            uint64_t addr = (physical_page_accessed << LOG2_BLOCK_SIZE) + (i << LOG2_BLOCK_SIZE);
            prefetch_requests.push_back(addr);
        }
    }
*/