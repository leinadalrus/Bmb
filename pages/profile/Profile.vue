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

const profile = ref<IProfileInfo>()
</script>

<template>
    <Dashboard />

    <section>
        <div>
            <AlbumArt :title="profile?.title" :image="profile?.image" />
        </div>

        <TradingCard
            :author="profile?.username"
            :content="profile?.description"
            :image="profile?.image"
        />
    </section>
</template>
