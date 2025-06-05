<script setup lang="ts">
import AlbumArt from '../(components)/AlbumArt.vue'
import TradingCard from '../(components)/TradingCard.vue'
import Dashboard from '../dashboard/Dashboard.vue'

interface IProfileInfo {
    username: string
    group: string
    image: string
    title: string
    description: string
}
</script>

<template>
    <Dashboard />

    <section>
        <div>
            <AlbumArt />
        </div>

        <TradingCard />
    </section>
</template>
