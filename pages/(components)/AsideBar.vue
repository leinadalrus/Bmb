<script setup lang="ts">
import SearchField from './SearchField.vue'
</script>

<template>
    <div
        class="fixed top-0 right-0 z-40 w-64 h-screen \
        transition-transform -translate-x-full sm:-translate-x-sm xs:-translate-x-xs p-4 mx-1"
    >
        <aside class="flex flex-col items-center justify-center gap-6">
            <img class="img-circle elevation-2" src="" alt="" />

            <h1>Find Original Creations</h1>
            <ul class="nav nav-pills">
                <li class="nav-item">Free</li>
                <li class="nav-item">Featured</li>
                <li class="nav-item">Exclusive</li>
                <li class="nav-item">Discounted</li>
            </ul>

            <h2>Product Formats</h2>
            <ul class="nav nav-pills">
                <li class="nav-item">Games</li>
                <li class="nav-item">Comics</li>
                <li class="nav-item">Illustrations</li>
                <li class="nav-item">Music</li>
                <li class="nav-item">Videos</li>
                <li class="nav-item">Softwares</li>
                <li class="nav-item">Accessories</li>
                <li class="nav-item">Miscellaneous</li>
            </ul>

            <h3>Events</h3>
            <ul class="nav nav-pills">
                <li class="nav-item">Promotional Events</li>
            </ul>

            <SearchField />
        </aside>
    </div>
</template>
