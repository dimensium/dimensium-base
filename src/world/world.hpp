#pragma once

#include "base/base.hpp"
#include <bitset>
#include <optional>
#include <unordered_map>

namespace dimensium 
{


    class WorldFile
    {
        public:
            enum struct Flags : uint32;

            struct BorderProperties
            {
                double center_x;
                double center_z;
                float damage_per_block;
                float safe_zone;
                double size;
                double size_lerp_target;
                double size_lerp_time;

                float warning_blocks;
                float warning_time;
            };

            
            
            struct CustomBossEvents
            {

            };

            

        public:


            static bool bitAnd(Flags, Flags);

            bool allowCommands(void) const;
            bool hasLockedDifficulty(void) const;
            bool turnsToSpectatorAfterDeathOfPlayer(void) const;
            bool wasSuccessfullyInitialized(void) const;
            bool isRainingNow(void) const;
            bool isThunderingNow(void) const;
            bool wasOpenedInAModifiedVersion(void) const;

        

        private:
            Flags flags;
            BorderProperties border_properties;
            int clear_weather_remaining_time;
            std::optional<CustomBossEvents> custom_boss_events;
    };


    
    enum struct WorldFile::Flags : uint32
    {
        allow_commands                              = 0x00000001u,
        locked_difficulty                           = 0x00000002u,
        turns_to_spectator_after_death_of_player    = 0x00000004u,
        successfully_initialized                    = 0x00000008u,
        raining_now                                 = 0x00000010u,
        thundering_now                              = 0x00000020u,
        was_opened_in_a_modified_version            = 0x00000040u,
    };

    

    // static member function
    [[nodiscard]] inline bool WorldFile::bitAnd(Flags a, Flags b)
    {
        return uint32(a) & uint32(b);
    }

    
    [[nodiscard]] inline bool WorldFile::allowCommands(void) const
    {
        return bitAnd(flags, Flags::allow_commands);
    }
    [[nodiscard]] inline bool WorldFile::hasLockedDifficulty(void) const
    {
        return bitAnd(flags, Flags::locked_difficulty);
    }
    [[nodiscard]] inline bool WorldFile::turnsToSpectatorAfterDeathOfPlayer(void) const
    {
        return bitAnd(flags, Flags::turns_to_spectator_after_death_of_player);
    }
    [[nodiscard]] inline bool WorldFile::wasSuccessfullyInitialized(void) const
    {
        return bitAnd(flags, Flags::successfully_initialized);
    }
    [[nodiscard]] inline bool WorldFile::isRainingNow(void) const
    {
        return bitAnd(flags, Flags::raining_now);
    }
    [[nodiscard]] inline bool WorldFile::isThunderingNow(void) const
    {
        return bitAnd(flags, Flags::thundering_now);
    }
    [[nodiscard]] inline bool WorldFile::wasOpenedInAModifiedVersion(void) const
    {
        return bitAnd(flags, Flags::was_opened_in_a_modified_version);
    }

    

    
}