<script setup lang="ts">
import CardView from './CardView.vue'
import Poster from './Poster.vue';
import SearchField from './SearchField.vue'
</script>

<template>
    <div
        class="fixed top-0 right-0 z-40 w-64 h-screen \ transition-transform -translate-x-full sm:-translate-x-sm xs:-translate-x-xs p-4 mx-1"
    >
        <aside class="flex flex-col items-center justify-center gap-6">
            <h1>Gear-flat</h1>

            <Poster />

            <h2>Dashboard</h2>

            <a class="">Games</a>
            <a class="">Comics</a>
            <a class="">Illustrations</a>
            <a class="">Music</a>
            <a class="">Videos</a>
            <a class="">Softwares</a>
            <a class="">Accessories</a>
            <a class="">Miscellaneous</a>

            <h2>Pages</h2>

            <a class="">Free</a>
            <a class="">Featured</a>
            <a class="">Exclusive</a>
            <a class="">Discounted</a>

            <h2>Misc.</h2>

            <a class="">Promotional events</a>

            <SearchField />
        </aside>
    </div>
</template>
